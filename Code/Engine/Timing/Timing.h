#ifndef TIMING_H
#define TIMING_H

#include <Windows.h>

namespace Engine
{
	namespace Timing
	{
		class Timing
		{
		public:
			~Timing();
			
			static Timing* GetTimer();

			void Initialize();
			float GetElapsedSecondCount_total();
			float GetElapsedSecondCount_duringPreviousFrame();
			void OnNewFrame();
			void StopTimer();

		private:
			Timing();
			Timing(const Timing& i_timing);
			Timing& operator=(const Timing& i_timing);

			static Timing* m_timing;

			double m_secondsPerTick;
			LARGE_INTEGER m_totalTicksElapsed_atInitializion;
			LARGE_INTEGER m_totalTicksElapsed_duringRun;
			LARGE_INTEGER m_totalTicksElapsed_previousFrame;
		};
	}
}

#endif