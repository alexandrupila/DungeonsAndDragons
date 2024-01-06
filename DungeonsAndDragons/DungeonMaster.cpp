#include "DungeonMaster.h"
#include "GenericException.h"

int DungeonMaster::calculateDiceResult(int difficultyClass, int statValue)
{
	int rezultat_zar = zar.rollDice();
	std::cout << "Se arunca zarul si se obtine " << rezultat_zar << std::endl;
	
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
	
	if (rezultat_zar < 0) rezultat_zar = 0;
	if (rezultat_zar > 30) rezultat_zar = 30;

	std::cout << "Dupa aplicarea modifier ului s-a obtinut " << rezultat_zar << std::endl;

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
	std::cout << "Introdu numele personajului tau:";
	std::string nume_personaj_player;
	std::cin >> nume_personaj_player;
	player_joc.setName(nume_personaj_player);

	std::cout << "Player character ul are default 100 hp" << std::endl;
	player_joc.setHitPoints(100);

	std::cout << "Alege rasa caracterului tau:" << std::endl;
	for (int i = 0; i < scenariu_joc.rase_joc.size(); i++)
	{
		std::cout << i + 1 << ":" << scenariu_joc.rase_joc[i].getName() << std::endl;
	}
	int nr_rasa;
	std::cin >> nr_rasa;
	player_joc.setRasa(scenariu_joc.rase_joc[nr_rasa - 1]);

	std::cout << "Alege clasa caracterului tau:" << std::endl;
	for (int i = 0; i < scenariu_joc.clase_joc.size(); i++)
	{
		std::cout << i + 1 << ":" << scenariu_joc.clase_joc[i].getName() << std::endl;
	}
	int nr_clasa;
	std::cin >> nr_clasa;
	player_joc.setClasa(scenariu_joc.clase_joc[nr_clasa - 1]);

	for (int i = 0; i < scenariu_joc.stats_name.size(); i++)
	{
		player_joc.addStat(scenariu_joc.stats_name[i], 0);
	}

	std::cout << "Alege stats-urile caracterului tau(suma totala trebuie sa fie de 50)" << std::endl;
	int nr_puncte_ramase = 50;
	while (1)
	{	
		if (nr_puncte_ramase == 0)
		{
			std::cout << "Ai alocat toate punctele. Doresti sa continui?[Y/N]";
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

		std::cout << "Mai ai " << nr_puncte_ramase << "(de) puncte" << std::endl;
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

		std::cout << "Introdu numarul de puncte pe care doresti sa il aloci:";

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


}

void DungeonMaster::initGame()
{
	scenariu_joc.readScenariu();
	createPlayerCharacter();
}

void DungeonMaster::fightEnemy(Personaj inamic)
{	
	int player_turn = 1;

	int hp_player = player_joc.getHP();
	int hp_inamic = inamic.getHP();

	while (1)
	{
		std::cout << "HP Player:" << hp_player << std::endl;
		std::cout << "HP Inamic:" << hp_inamic << std::endl;

		std::cout << "Este tura ta: ce fel de abilitate vrei sa folosesti?" << std::endl;

		std::cout << "1.Abilitate specifica rasei." << std::endl;
		std::cout << "2.Abilitate specifica clasei." << std::endl;

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
			std::cout << "Alege abilitatea pe care doresti sa o folosesti:" << std::endl;
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
			std::cout << "Alege abilitatea pe care doresti sa o folosesti:" << std::endl;
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

		std::cout << "O sa folosesti abilitatea " << abilitate_folosita.getName() << std::endl;

		//TODO: Implementare damage
	}

}

void DungeonMaster::test()
{
	fightEnemy(scenariu_joc.inamici_joc[0]);
}
