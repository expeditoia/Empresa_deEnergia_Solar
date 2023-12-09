#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <clocale>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <Windows.h>
using namespace std;
#include "Produtos/Produto.cpp"
#include "Produtos/Inversores.cpp"
#include "Produtos/Interruptor.cpp"
#include "Produtos/DisjuntorDDR.cpp"
#include "Produtos/Placas_Solares.cpp"
#include "Produtos/Baterias.cpp"
#include "Calcula/MetodosCalcula.cpp"
#include "Estoque/EstoqueBaterias.cpp"
#include "Estoque/EstoqueInversores.cpp"
#include "Estoque/EstoqueDisjuntor.cpp"
#include "Estoque/EstoqueInterruptor.cpp"
#include "Estoque/EstoquePlacas.cpp"
#include "FunçõesPrincipais/FunçõesPrincipais.cpp"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	system("color 70");
	menuPrincipal();
	switch(opcao)
	{
		case 1:
          administrador();
	          switch(opcaoDesejadaDoMenu)
	          {
	               case 1:
	                      loginADM();
	                      main();
	                      break;
	               case 2:
	                      registroADM();
	                      system("pause");
	                      system("cls");
	                      main();
	                      break;
	               case 3:
	                      pesquisa();
	                      system("cls");
	                      main();
	                      break;
	
	               case 0:
	               		  system("cls");
	                      main();
	                      break;
	             default:
	                      system("cls");
	                      escolhaErrada();
	                      main();
	                      break;
			  }
	          break;
	    case 2:
	    		cliente();
				switch(opcaoDesejadaDoMenu2)
				{
				    case 1:
                           loginCl();
                           system("cls");
					       main();
					       break;
			        case 2:
					       registroCl();
					       system("cls");
                           main();
                           break;
                    case 3:
					       pesquisa();
					       system("cls");
					       main();
					       break;
                    case 0:
                           system("cls");
					       main();
					       break;
			        default:
                           escolhaErrada();
                           main();
                }
                break;
        case 0:
        	break;
		default:
        		escolhaErrada();
        		break;
	}
	return 0;
}
