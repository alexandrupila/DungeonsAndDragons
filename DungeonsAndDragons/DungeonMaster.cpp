#include "DungeonMaster.h"
#include "GenericException.h"

int DungeonMaster::calculateDiceResult(int difficultyClass, int statValue,std::string stat)
{
	int rezultat_zar = zar.rollDice();
	Logger::getInstance().logMessage("Se arunca zarul si se obtine ");
	Logger::getInstance().logMessage(std::to_string(rezultat_zar) + "\n");
	
	switch (statValue)
	{
	case 0:
		rezultat_zar -= 5;
		break;
	case 1:
		rezultat_zar -= 5;
		break;
	case 2:
		rezultat_zar -= 4;
		break;
	case 3:
		rezultat_zar -= 4;
		break;
	case 4:
		rezultat_zar -= 3;
		break;
	case 5:
		rezultat_zar -= 3;
		break;
	case 6:
		rezultat_zar -= 2;
		break;
	case 7:
		rezultat_zar -= 2;
		break;
	case 8:
		rezultat_zar -= 1;
		break;
	case 9:
		rezultat_zar -= 1;
		break;
	case 10:
		rezultat_zar += 0;
		break;
	case 11:
		rezultat_zar += 0;
		break;
	case 12:
		rezultat_zar += 1;
		break;
	case 13:
		rezultat_zar += 1;
		break;
	case 14:
		rezultat_zar += 2;
		break;
	case 15:
		rezultat_zar += 2;
		break;
	case 16:
		rezultat_zar += 3;
		break;
	case 17:
		rezultat_zar += 3;
		break;
	case 18:
		rezultat_zar += 4;
		break;
	case 19:
		rezultat_zar += 4;
		break;
	case 20:
		rezultat_zar += 5;
		break;
	case 21:
		rezultat_zar += 5;
		break;
	case 22:
		rezultat_zar += 6;
		break;
	case 23:
		rezultat_zar += 6;
		break;
	case 24:
		rezultat_zar += 7;
		break;
	case 25:
		rezultat_zar += 7;
		break;
	case 26:
		rezultat_zar += 8;
		break;
	case 27:
		rezultat_zar += 8;
		break;
	case 28:
		rezultat_zar += 9;
		break;
	case 29:
		rezultat_zar += 9;
		break;
	case 30:
		rezultat_zar += 10;
		break;
	default:
		break;
	}

	if (player_joc.getRace().getBonus().first == stat)
	{
		rezultat_zar += player_joc.getRace().getBonus().second;
	}

	if (rezultat_zar < 0) rezultat_zar = 0;
	if (rezultat_zar > 30) rezultat_zar = 30;

	Logger::getInstance().logMessage("Dupa aplicarea modifier ului s-a obtinut " + std::to_string(rezultat_zar) + "\n");

	if (rezultat_zar >= difficultyClass)
	{
		std::cout << "Actiunea a avut succes" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Actiunea a esuat" << std::endl;
		return 0;
	}

}

void DungeonMaster::createPlayerCharacter()
{	
	Logger::getInstance().logMessage("Introdu numele personajului tau:");
	std::string nume_personaj_player;
	std::cin >> nume_personaj_player;
	player_joc.setName(nume_personaj_player);

	Logger::getInstance().logMessage("Player character ul are default 60 hp");
	Logger::getInstance().logMessage("\n");
	player_joc.setHitPoints(60);

	Logger::getInstance().logMessage("Alege rasa caracterului tau:");
	Logger::getInstance().logMessage("\n");
	for (int i = 0; i < scenariu_joc.rase_joc.size(); i++)
	{
		std::cout << i + 1 << ":";
		std::cout << scenariu_joc.rase_joc[i];
		std::cout << "\n";
	}
	int nr_rasa;
	std::cin >> nr_rasa;
	player_joc.setRasa(scenariu_joc.rase_joc[nr_rasa - 1]);
	system("cls");
	Logger::getInstance().logMessage("Alege clasa caracterului tau:");
	Logger::getInstance().logMessage("\n");
	for (int i = 0; i < scenariu_joc.clase_joc.size(); i++)
	{
		std::cout << i + 1 << ":";
		std::cout << scenariu_joc.clase_joc[i];
		std::cout << "\n";
	}

	int nr_clasa;
	std::cin >> nr_clasa;
	player_joc.setClasa(scenariu_joc.clase_joc[nr_clasa - 1]);

	system("cls");

	for (int i = 0; i < scenariu_joc.stats_name.size(); i++)
	{
		player_joc.addStat(scenariu_joc.stats_name[i], 0);
	}

	Logger::getInstance().logMessage("Alege stats-urile caracterului tau(suma totala trebuie sa fie de 50)");
	Logger::getInstance().logMessage("\n");
	int nr_puncte_ramase = 50;
	while (1)
	{	
		if (nr_puncte_ramase == 0)
		{
			Logger::getInstance().logMessage("Ai alocat toate punctele. Doresti sa continui?[Y/N]");
			char answer;
			std::cin >> answer;

			try {
				if (answer != 'Y' and answer != 'N')
				{
					throw GenericException("Raspunusul nu are sens.");
				}
			}
			catch (GenericException& exceptie)
			{
				exceptie.printException();
				continue;
			}

			if (answer == 'Y') break;
		}

		Logger::getInstance().logMessage("Mai ai " + std::to_string(nr_puncte_ramase) + "(de) puncte");
		Logger::getInstance().logMessage("\n");
		for (int i = 0; i < scenariu_joc.stats_name.size(); i++)
		{
			std::cout << i + 1 << ":" << scenariu_joc.stats_name[i] << " " << player_joc.getStatValue(scenariu_joc.stats_name[i]) << std::endl;
		}

		int stats_index;

		std::cin >> stats_index;

		try
		{
			if (stats_index<1 or stats_index>scenariu_joc.stats_name.size() + 1)
			{
				throw GenericException("Index-ul ales este invalid.");
			}
		}
		catch (GenericException& exceptie)
		{
			exceptie.printException();
			continue;
		}

		int nr_puncte_de_alocat;

		Logger::getInstance().logMessage("Introdu numarul de puncte pe care doresti sa il aloci:");

		std::cin >> nr_puncte_de_alocat;

		try
		{
			if (nr_puncte_de_alocat > nr_puncte_ramase)
			{
				throw GenericException("Nu mai ai destule puncte de alocat");
			}
			if (nr_puncte_de_alocat < 0)
			{
				int nr_pct_stats_curent = player_joc.getStatValue(scenariu_joc.stats_name[stats_index - 1]);
				if (nr_pct_stats_curent + nr_puncte_de_alocat < 0)
				{
					throw GenericException("Ai incercat sa aloci puncte in minus!");
				}
			}
		}

		catch (GenericException& exceptie)
		{
			exceptie.printException();
			continue;
		}

		int nr_pct_stats_curent = player_joc.getStatValue(scenariu_joc.stats_name[stats_index - 1]);
		nr_pct_stats_curent += nr_puncte_de_alocat;
		nr_puncte_ramase -= nr_puncte_de_alocat;

		player_joc.setStat(scenariu_joc.stats_name[stats_index - 1],nr_pct_stats_curent);
		
		

	}

	Logger::getInstance().logMessage("Introdu trecutul personajului tau: ");
	std::string trecut;
	std::cin >> trecut;
	player_joc.setTrecut(trecut);


}

void DungeonMaster::initGame()
{
	scenariu_joc.readScenariu();
	current_room = scenariu_joc.starting_room;
	createPlayerCharacter();
}

void DungeonMaster::fightEnemy(Personaj inamic)
{	
	int player_turn = 1;

	int hp_player = player_joc.getHP();
	int hp_inamic = inamic.getHP();

	while (1)
	{
		Logger::getInstance().logMessage("HP Player:" + std::to_string(hp_player));
		Logger::getInstance().logMessage("\n");
		Logger::getInstance().logMessage("HP Inamic:" + std::to_string(hp_inamic));
		Logger::getInstance().logMessage("\n");

		if (player_turn)
		{
			Logger::getInstance().logMessage("Este tura ta: ce fel de abilitate vrei sa folosesti?");
			Logger::getInstance().logMessage("\n");
			Logger::getInstance().logMessage("1.Abilitate specifica rasei.");
			Logger::getInstance().logMessage("\n");
			Logger::getInstance().logMessage("2.Abilitate specifica clasei.");
			Logger::getInstance().logMessage("\n");

			int tip_abilitate;

			std::cin >> tip_abilitate;

			try
			{
				if (tip_abilitate != 1 and tip_abilitate != 2)
				{
					throw(GenericException("Inputul este invalid."));
				}
			}
			catch (GenericException& exceptie)
			{
				exceptie.printException();
				continue;
			}

			Abilitate abilitate_folosita;

			if (tip_abilitate == 1)
			{
				Logger::getInstance().logMessage("Alege abilitatea pe care doresti sa o folosesti:");
				Logger::getInstance().logMessage("\n");
				for (int i = 0; i < player_joc.getRace().getAbilities().size(); i++)
				{
					std::cout << "Abilitatea " << i + 1 << std::endl;
					std::cout << player_joc.getRace().getAbilities()[i];
				}
				int nr_abilitate;

				std::cin >> nr_abilitate;
				try
				{
					if (nr_abilitate<1 or nr_abilitate>player_joc.getRace().getAbilities().size())
					{
						throw(GenericException("Inputul este invalid."));
					}
				}
				catch (GenericException& exceptie)
				{
					exceptie.printException();
					continue;
				}
				abilitate_folosita = player_joc.getRace().getAbilities()[nr_abilitate - 1];

			}
			else
			{
				Logger::getInstance().logMessage("Alege abilitatea pe care doresti sa o folosesti:");
				Logger::getInstance().logMessage("\n");
				for (int i = 0; i < player_joc.getClass().getAbilities().size(); i++)
				{
					std::cout << "Abilitatea " << i + 1 << std::endl;
					std::cout << player_joc.getClass().getAbilities()[i];
				}
				int nr_abilitate;

				std::cin >> nr_abilitate;
				try
				{
					if (nr_abilitate<1 or nr_abilitate>player_joc.getClass().getAbilities().size())
					{
						throw(GenericException("Inputul este invalid."));
					}
				}
				catch (GenericException& exceptie)
				{
					exceptie.printException();
					continue;
				}
				abilitate_folosita = player_joc.getClass().getAbilities()[nr_abilitate - 1];
			}

			Logger::getInstance().logMessage("O sa folosesti abilitatea ");
			Logger::getInstance().logMessage("\n");

			if (calculateDiceResult(abilitate_folosita.getDifficultyClass(), player_joc.getStatValue(abilitate_folosita.getStatRequired()), abilitate_folosita.getStatRequired()) == 1)
			{
				hp_inamic -= abilitate_folosita.getDamage();
				Logger::getInstance().logMessage("Ai cauzat " + std::to_string(abilitate_folosita.getDamage()) + " damage inamicului tau!");
				Logger::getInstance().logMessage("\n");
			}
			else
			{
				Logger::getInstance().logMessage("Abilitatea a esuat!");
				Logger::getInstance().logMessage("\n");
			}

			player_turn = 0;
		}
		else
		{
		Logger::getInstance().logMessage("Este randul inamicului sa loveasca!");
		Logger::getInstance().logMessage("\n");

		Sleep(2000);

			int tip_abilitate = rand() % 2;
			
			Abilitate abilitate_folosita;

			if (tip_abilitate == 0)
			{
				int nr_abilitate = rand() % inamic.getRace().getAbilities().size();
				abilitate_folosita = inamic.getRace().getAbilities()[nr_abilitate];
			}
			else
			{
				int nr_abilitate = rand() % inamic.getClass().getAbilities().size();
				abilitate_folosita = inamic.getClass().getAbilities()[nr_abilitate];
			}

			Logger::getInstance().logMessage("Inamicul o sa foloseasca abilitatea " + abilitate_folosita.getName());
			Logger::getInstance().logMessage("\n");

			if (calculateDiceResult(abilitate_folosita.getDifficultyClass(), inamic.getStatValue(abilitate_folosita.getStatRequired()), abilitate_folosita.getStatRequired()) == 1)
			{
				hp_player -= abilitate_folosita.getDamage();
				Logger::getInstance().logMessage("Inamicul ti-a cauzat " + std::to_string(abilitate_folosita.getDamage()) + " damage!");
				Logger::getInstance().logMessage("\n");
			}
			else
			{
				Logger::getInstance().logMessage("Abilitatea a esuat!");
				Logger::getInstance().logMessage("\n");
			}

			player_turn = 1;

		}

		if (hp_inamic <= 0)
		{
			Logger::getInstance().logMessage("Ai invins inamicul!");
			Logger::getInstance().logMessage("\n");
			current_room->removeEnemy(inamic);
			break;
		}
		if(hp_player<=0)
		{
			Logger::getInstance().logMessage("Ai fost invins si ai pierdut jocul!");
			Logger::getInstance().logMessage("\n");
			exit(0);
		}

	}

}

void DungeonMaster::interactWithRoom()
{	
	while (1)
	{
		std::cout << *current_room;

		Logger::getInstance().logMessage("Introdu actiunea pe care doresti sa o realizez: ");

		int index_actiune;
		std::cin >> index_actiune;
		try {

			if (index_actiune<1 or index_actiune>current_room->getInamici().size() + current_room->getObiecte().size())
			{
				throw(GenericException("Valoarea introdusa este invalida."));
			}
		}
		catch (IException& exceptie)
		{
			exceptie.printException();
			continue;
		}
		
		if (index_actiune <= current_room->getObiecte().size())
		{
			if (calculateDiceResult(current_room->getObiecte()[index_actiune - 1]->getDifficultyClass(), player_joc.getStatValue(current_room->getObiecte()[index_actiune - 1]->getStat()),current_room->getObiecte()[index_actiune-1]->getStat()) == 1)
			{	

				ObiectSchimbareScena* obj_schimb_scena = dynamic_cast<ObiectSchimbareScena*>(current_room->getObiecte()[index_actiune - 1]);

				if (obj_schimb_scena == nullptr)
				{
					current_room->getObiecte()[index_actiune - 1]->interactioneaza();
					current_room->removeObject(current_room->getObiecte()[index_actiune - 1]);
				}
				else
				{
					obj_schimb_scena->interactioneaza();
					std::string new_room_name = obj_schimb_scena->getNewRoomName();
					setNewRoom(new_room_name);
					system("cls");

				}
				
			}
		}
		else
		{
			fightEnemy(current_room->getInamici()[index_actiune - current_room->getObiecte().size() - 1]);
		}

	}

}

void DungeonMaster::setNewRoom(std::string newRoomName)
{
	for (int i = 0; i < scenariu_joc.camere_joc.size(); i++)
	{
		if (scenariu_joc.camere_joc[i].getRoomName() == newRoomName)
		{
			current_room = &scenariu_joc.camere_joc[i];
			break;
		}
	}
}

void DungeonMaster::test()
{
	interactWithRoom();
}

void DungeonMaster::playGame()
{
	initGame();
	while (1)
	{
		interactWithRoom();
	}
}

DungeonMaster::DungeonMaster()
{
	srand(time(NULL));
	current_room = nullptr;
}
