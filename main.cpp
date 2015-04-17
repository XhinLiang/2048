#include "Block.h"
#include "Menu.h"
#include "NumberData.h"

int main()
{
	Block block;
	Menu menu;
	bool conFlag = true;

	while (conFlag)
	{
		switch (menu.MainSelect())
		{
			case 0:
				block.Game();
				break;

			case 1:
				block.SetNew();
				block.Game();
				break;

			case 2:
				NumberData::Load(menu.SaveSelect(), block);
				block.Game();
				break;

			case 3:
				NumberData::Save(menu.SaveSelect(), block);
				break;

			case 4:
				conFlag = false;
				break;

			default:
				break;
		}
	}

	return 0;
}
