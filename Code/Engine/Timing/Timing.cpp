#include "Timing.h"

#include "../DebugFunctions/DebugFunctions.h"

namespace Engine
{
	namespace Timing
	{
		Timing* Timing::m_timing = 0;
		
		Timing::Timing() : m_secondsPerTick(0.0f), m_totalTicksElapsed_atInitializion({ 0 }), m_totalTicksElapsed_duringRun({ 0 }), 
			m_totalTicksElapsed_previousFrame({ 0 }), m_isInitialized(false)
		{
			
		}

		Timing::~Timing()
		{

		}

		Timing* Timing::GetTimer()
		{
			if (m_timing == 0)
			{
				m_timing = new Timing;
			}

			return m_timing;
		}
		
		void Timing::Initialize()
		{
			if (!m_isInitialized)
			{
				LARGE_INTEGER tickspersecond = { 0 };
				if (QueryPerformanceFrequency(&tickspersecond) != FALSE)
				{
					if (tickspersecond.QuadPart != 0.0)
					{
						m_secondsPerTick = 1.0 / static_cast<double>(tickspersecond.QuadPart);
					}
					else
					{
						DEBUG_PRINT("Hardware doesn't support high resolution performance counters");
						assert(false);
					}
				}
				else
				{
					DEBUG_PRINT("Windows failed to query performance frequency");
					assert(false);
				}

				if (QueryPerformanceCounter(&m_totalTicksElapsed_atInitializion) == FALSE)
				{
					DEBUG_PRINT("Windows failed to query performance counter");
					assert(false);
				}

				m_isInitialized = true;
				DEBUG_PRINT("Initialized timer");
			}
			else
			{
				DEBUG_PRINT("Timer has already been initialized");
			}
		}

		float Timing::GetElapsedSecondCount_total()
		{
			if (!m_isInitialized)
			{
				Initialize();
			}
			
			return static_cast<float>(static_cast<double>(m_totalTicksElapsed_duringRun.QuadPart) * m_secondsPerTick);
		}

		float Timing::GetElapsedSecondCount_duringPreviousFrame()
		{
			if (!m_isInitialized)
			{
				Initialize();
			}
			
			return static_cast<float>(static_cast<double>(m_totalTicksElapsed_duringRun.QuadPart - m_totalTicksElapsed_previousFrame.QuadPart) * m_secondsPerTick);
		}

		void Timing::OnNewFrame()
		{
			if (!m_isInitialized)
			{
				Initialize();
			}
			
			m_totalTicksElapsed_previousFrame = m_totalTicksElapsed_duringRun;

			LARGE_INTEGER totalTicksElapsed = { 0 };
			const BOOL result = QueryPerformanceCounter(&totalTicksElapsed);

			assert(result != false);

			m_totalTicksElapsed_duringRun.QuadPart = totalTicksElapsed.QuadPart - m_totalTicksElapsed_atInitializion.QuadPart;
		}

		void Timing::StopTimer()
		{
			if (m_timing != 0)
			{
				delete m_timing;
				m_isInitialized = false;

				DEBUG_PRINT("Destroyed Timer");
			}
			else
			{
				DEBUG_PRINT("Timer does not exist for destruction");
			}
		}
	}
}