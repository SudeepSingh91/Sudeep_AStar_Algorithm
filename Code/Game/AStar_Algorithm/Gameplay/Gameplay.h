#ifndef GAMEPLAY_H
#define GAMEPLAY_H

namespace Game
{
	namespace Gameplay
	{
		class Sprite;
		
		class Gameplay
		{
		public:
			static Gameplay* InitiateGame();
			~Gameplay();

			void Update(const float dt);

		private:
			Gameplay();
			Gameplay(const Gameplay& i_gameplay);
			Gameplay operator=(const Gameplay& i_gameplay);

			static Gameplay* m_gameplay;

			bool m_isInitialized;
		};
	}
}

#endif