#include "FunçõesPrincipais.hpp"
using namespace std;
int alt, retorna, retorna2, ch;
string  reguser,regpass,ru,rp;
string  user,pass,cdadm, codeadm;
float  precoDoProduto, c;
string  nomeDoProduto, codigoBarras;
string u,p, x , y, w, z ;
int num_executions, op, opcaoMenu2, opcaoMenu3, opcaoDesejadaDoMenu, opcaoDesejadaDoMenu2, opcao, variavel;
string capacidadeDeArmazenamento, voltagemDeSaida, capacidadeDeGeracaoWatts, tensaoSuportada;
Placas obj2;
DisjuntoreDifResDDR obj5;
Inversores obj3;
Baterias obj1;
Baterias obj10;
InterruptoresDR obj4;
Estoque g;
string codigoBarrasComp, precoDoProdutoComp, capacidadeDeGeracaoWattsComp, idrTrueFalse, amperesSuportado;
float potencia, gasto;
void menuAdm();
void exibiAoAdm();
void principal();
void calculaPlacasEBaterias();
void abreEstoquePlacasVendidas(string reguser);
void abreEstoqueBateriasVendidas(string reguser);
void abreEstoqueInversoresVendidos(string reguser);
void abreEstoqueDisjuntoresVendidos(string reguser);
void abreEstoqueInterruptoresVendidos(string reguser);
void exibiMenuPlacas();
void exibiMenuBaterias();
void exibiMenuInversores();
void exibiAoCliente();
void escolhaErrada();
void removerBaterias(string reguser);
void removerPlacas(string reguser);
void removerPlacasVendidas(string reguser);
void removerBateriasVendidas(string reguser);
void removerInversoresVendidos(string reguser);
void removerInversores(string reguser);
void removerDisjuntores(string reguser);
void removerInterruptores(string reguser);
void removerDisjuntoresVendidos(string reguser);
void removerInterruptoresVendidos(string reguser);
void abreEstoqueBaterias(string reguser);
void abreEstoquePlacas(string reguser);
void abreEstoqueInversores(string reguser);
void abreEstoqueInterruptores(string reguser);
void abreEstoqueDisjuntores(string reguser);
void loginADM();
void loginCl();
void pesquisa();
void registroADM();
void registroCl();
void menuPrincipal();
void administrador();
void cliente();
void exibiAoClienteOP();
void exibiMenuInterruptores();
void exibiMenuDisjuntores();
void principal()
{
	do{
    	system("cls");
        menuAdm();
        Empresa_Solar calcula;

		cout<< "\n\nEscolha uma opção: ";
        cin >> opcao;

        system("cls");

        if(opcao == 34){
            break;
        }

        switch (opcao) {
            case 1:
                cin.ignore();
				system("cls");
                exibiMenuBaterias();
                cout<<"Insira a marca do produto ";
                getline(cin, nomeDoProduto);

                cout<<"Insira o preço: ";
                cin>> precoDoProduto;

                cout<<"Código de barras: ";
                cin>>codigoBarras;

                cout<<"Capacidade de armazenamento: ";
                cin>> capacidadeDeArmazenamento;

                cout<<"Voltagem de saída: ";
                cin>> voltagemDeSaida;
		        obj1.setNomeDoProduto(nomeDoProduto);
		        obj1.setPrecoDoProduto(precoDoProduto);
		        obj1.setCodigoBarras(codigoBarras);
		        obj1.setCapacidadeDeArmazenamento(capacidadeDeArmazenamento);
		        obj1.setVoltagemDeSaida(voltagemDeSaida);
			    if(g.adicionaBaterias(obj1)){
			        system("pause");
			        system("cls");
			        cout<<"Bateria adicionada.\n";
			        removerBaterias(reguser);
    				g.salvarNoArquivoBaterias(reguser);
			    }
			    else{
			        cout<<"Não foi possível cadastrar a bateria.\n";
			    }
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                exibiMenuBaterias();
        		g.exibiAsBateriasDisponiveis();
				cout<<"\nDigite o nome ou marca: ";
				cin >>nomeDoProduto;
				if(g.venderBaterias(nomeDoProduto)){
                    cout<<"Bateria vendida.\n";
                    removerBaterias(reguser);
    				g.salvarNoArquivoBaterias(reguser);
    				removerBateriasVendidas(reguser);
    				g.salvarNoArquivoBateriasVendidas(reguser);
                }
                else{
                    cout<<"Não foi vender a bateria.\n";
                }

                system("pause");
                system("cls");
                break;
            case 3:
                exibiMenuBaterias();
            	cout<<"Digite o nome do produto a ser removido : ";
	            getline(cin,nomeDoProduto);

	            if(g.removerBateriasDoEstoque(nomeDoProduto)){
	                cout<<"Produto removido.\n";
	                removerBaterias(reguser);
    				g.salvarNoArquivoBaterias(reguser);
	            }
	            else{
	                cout<<"Não foi realizar essa operação.\n";
	            }

			    system("pause");
	            system("cls");
                break;
            case 4:
                exibiMenuBaterias();
				g.exibiAsBateriasDisponiveis();
            	system("pause");
            	system("cls");
                break;
            case 5:
                exibiMenuBaterias();
				cout<<"Digite o nome da bateria a ser pesquisada ";
                getline(cin,nomeDoProduto);

                g.exibiNomesDasBaterias(nomeDoProduto);

                system("pause");
                system("cls");
                break;
            case 6:
                exibiMenuBaterias();
				g.exibiBateriasVendidas();

                system("pause");
                system("cls");
                break;
            case 7:
                cin.ignore();
				system("cls");
                exibiMenuPlacas();
                cout<<"Insira a marca do produto ";
                getline(cin,nomeDoProduto);
                cout<<"Código de barras: ";
                cin>> codigoBarras;
                cout<<"Insira o preço: ";
                cin>>precoDoProduto;
 	 	        cout<<"capacidade de geração Watts: ";
                cin>>capacidadeDeGeracaoWatts;

                obj2.setNomeDoProduto(nomeDoProduto);
                obj2.setPrecoDoProduto(precoDoProduto);
                obj2.setCodigoBarras(codigoBarras);
                obj2.setCapacidadeDeGeracaoWatts(capacidadeDeGeracaoWatts);

                if(g.adicionaPlacas_Solares(obj2)){
			        system("cls");
			        system("pause");
                    cout<<"Placa adicionada.\n";
                    removerPlacas(reguser);
                    g.salvarNoArquivoPlacas_Solares(reguser);
                }
                else{
                    cout<<"Não foi possível cadastrar a placa.\n";
                }
                system("cls");
                break;
            case 8:
                exibiMenuPlacas();
        		g.exibiPlacas_Solares();

                cout<<"\nDigite o nome ou marca: ";
                cin >>nomeDoProduto;
                if(g.venderPlacas_Solares(nomeDoProduto)){
                    cout<<"Placa Solar vendida.\n";
                    removerPlacas(reguser);
                    g.salvarNoArquivoPlacas_Solares(reguser);
                    removerPlacasVendidas(reguser);
                    g.salvarNoArquivoPlacas_SolaresVendidas(reguser);
                }
                else{
                    cout<<"Não foi possivel vender a placa.\n";
                }

                system("pause");
                system("cls");
                break;
            case 9:
                exibiMenuPlacas();
            	cout<<"Digite o nome do produto a ser removido : ";
	            cin >>nomeDoProduto;

	            if(g.removerPlacas_SolaresDoEstoque(nomeDoProduto)){
	                cout<<"Produto removido.\n";
	                removerPlacas(reguser);
                    g.salvarNoArquivoPlacas_Solares(reguser);
	            }
	            else{
	                cout<<"Não foi realizar essa operação.\n";
	            }

	            system("pause");
	            system("cls");
                break;
            case 10:
                exibiMenuPlacas();
				g.exibiPlacas_Solares();
                system("pause");
                system("cls");
                break;
            case 11:
                exibiMenuPlacas();
				cout<<"Digite o nome da Placa a ser pesquisada ";
                cin >>nomeDoProduto;
                g.exibiNomesDasPlacas_Solares(nomeDoProduto);
                system("pause");
                system("cls");
                break;
            case 12:
                exibiMenuPlacas();
				g.exibiPlacas_SolaresVendidas();

                system("pause");
                system("cls");
                break;
            case 13:
                cin.ignore();
				system("cls");
                exibiMenuInversores();
                cout<<"Insira a marca do produto ";
                cin>> nomeDoProduto;

                cout<<"Insira o preço: ";
                cin>>precoDoProduto;

                cout<<"Código de barras: ";
                cin>> codigoBarras;


 	 	        cout<<"capacidade de geração Watts: ";
                cin>>tensaoSuportada;

                obj3.setNomeDoProduto(nomeDoProduto);
                obj3.setPrecoDoProduto(precoDoProduto);
                obj3.setCodigoBarras(codigoBarras);
                obj3.setTensaoSuportada(tensaoSuportada);

                if(g.adicionaInversores(obj3)){
			        system("cls");
			        system("pause");
                    cout<<"Inversor adicionado.\n";
                    removerInversores(reguser);
                    g.salvarNoArquivoInversores(reguser);
                }
                else{
                    cout<<"Não foi possível cadastrar a placa.\n";
                }
                system("cls");
                break;
            case 14:
                exibiMenuInversores();
        		g.exibiInversores();

                cout<<"\nDigite o nome ou marca: ";
                cin >>nomeDoProduto;
                if(g.venderInversores(nomeDoProduto)){
                    cout<<"Inversor vendida.\n";
                    removerInversores(reguser);
                    g.salvarNoArquivoInversores(reguser);
                    removerInversoresVendidos(reguser);
                    g.salvarNoArquivoInversoresVendidos(reguser);
                }
                else{
                    cout<<"Não foi possivel vender o inversor.\n";
                }

                system("pause");
                system("cls");
                break;
            case 15:
                exibiMenuInversores();
            	cout<<"Digite o nome do produto a ser removido : ";
	            cin >>nomeDoProduto;

	            if(g.removerInversoresDoEstoque(nomeDoProduto)){
	                cout<<"Produto removido.\n";
	                removerInversores(reguser);
                    g.salvarNoArquivoInversores(reguser);
	            }
	            else{
	                cout<<"Não foi realizar essa operação.\n";
	            }

	            system("pause");
	            system("cls");
                break;
            case 16:
                exibiMenuInversores();
				g.exibiInversores();
                system("pause");
                system("cls");
                break;
            case 17:
                exibiMenuInversores();
				cout<<"Digite o nome da Placa a ser pesquisada ";
                cin >>nomeDoProduto;

                g.exibiNomesDasInversores(nomeDoProduto);

                system("pause");
                system("cls");
                break;
            case 18:
                exibiMenuInversores();
				g.exibiInversoresVendidos();

                system("pause");
                system("cls");
                break;
            case 19:
            	cin.ignore();
				system("cls");
                exibiMenuDisjuntores();
                cout<<"Insira a marca do produto ";
                cin>> nomeDoProduto;

                cout<<"Insira o preço: ";
                cin>>precoDoProduto;

                cout<<"Código de barras: ";
                cin>> codigoBarras;

 	 	        cout<<"Tensão suportada (volts): ";
                cin>>tensaoSuportada;

                cout<<"Ampéres suportado: ";
                cin>>amperesSuportado;

                cout<<"É com função IDR sim(s) ou não(n): ";
                cin>>idrTrueFalse;

                obj5.setNomeDoProduto(nomeDoProduto);
                obj5.setPrecoDoProduto(precoDoProduto);
                obj5.setCodigoBarras(codigoBarras);
                obj5.setTensaoSuportada(tensaoSuportada);
                obj5.setAmperesSuportado(amperesSuportado);
                obj5.setIdrTrueFalse(idrTrueFalse);

                if(g.adicionaDisjuntor(obj5)){
			        system("cls");
			        system("pause");
                    cout<<"Disjuntor adicionado.\n";
                    removerDisjuntores(reguser);
                    g.salvarNoArquivoDisjuntoreDifResDDR(reguser);
                }
                else{
                    cout<<"Não foi possível cadastrar.\n";
                }
                system("cls");
                break;
    	    case 20:
    	    	exibiMenuDisjuntores();
        		g.exibiDisjuntorDisponiveis();

                cout<<"\nDigite o nome ou marca: ";
                cin >>nomeDoProduto;
                if(g.venderDisjuntor(nomeDoProduto)){
                    cout<<"Disjuntor vendido.\n";
                    removerDisjuntores(reguser);
                    g.salvarNoArquivoDisjuntoreDifResDDR(reguser);
                    removerDisjuntoresVendidos(reguser);
                    g.salvarNoArquivoDisjuntoreDifResDDRVendidos(reguser);
                }
                else{
                    cout<<"Não foi possivel vender o inversor.\n";
                }

                system("pause");
                system("cls");
                break;
    	    case 21:
    	    	exibiMenuDisjuntores();
            	cout<<"Digite o nome do produto a ser removido : ";
	            cin >>nomeDoProduto;

	            if(g.removerDisjuntorDoEstoque(nomeDoProduto)){
	                cout<<"Produto removido.\n";
	                removerDisjuntores(reguser);
                    g.salvarNoArquivoDisjuntoreDifResDDR(reguser);
	            }
	            else{
	                cout<<"Não foi realizar essa operação.\n";
	            }

	            system("pause");
	            system("cls");
                break;
    	    case 22:
    	    	exibiMenuDisjuntores();
				g.exibiDisjuntorDisponiveis();
                system("pause");
                system("cls");
                break;
    	    case 23:
    	    	exibiMenuDisjuntores();
				cout<<"Digite o nome do disjuntor a ser pesquisado ";
                cin >>nomeDoProduto;

                g.exibiNomesDisjuntores(nomeDoProduto);

                system("pause");
                system("cls");
                break;
    	    case 24:
				exibiMenuDisjuntores();
				g.exibiDisjuntorVendidos();
                system("pause");
                system("cls");
                break;
    	    case 25:
    	    	cin.ignore();
				system("cls");
                exibiMenuInterruptores();
                cout<<"Insira a marca do produto ";
                cin>> nomeDoProduto;

                cout<<"Insira o preço: ";
                cin>>precoDoProduto;

                cout<<"Código de barras: ";
                cin>> codigoBarras;

 	 	        cout<<"Tensão suportada (volts): ";
                cin>>tensaoSuportada;

                cout<<"Ampéres suportado: ";
                cin>>amperesSuportado;
                obj4.setNomeDoProduto(nomeDoProduto);
                obj4.setPrecoDoProduto(precoDoProduto);
                obj4.setCodigoBarras(codigoBarras);
                obj4.setTensaoSuportada(tensaoSuportada);
                obj4.setAmperesSuportado(amperesSuportado);

                if(g.adicionaInterruptores(obj4)){
			        system("cls");
			        system("pause");
                    cout<<"inversor adicionado.\n";
                    removerInterruptores(reguser);
                    g.salvarNoArquivoInterruptoresDR(reguser);
                }
                else{
                    cout<<"Não foi possível cadastrar a placa.\n";
                }
                system("cls");
                break;
    	    case 26:
    	    	exibiMenuInterruptores();
        		g.exibiAsInterruptoresDisponiveis();

                cout<<"\nDigite o nome ou marca: ";
                cin >>nomeDoProduto;
                if(g.venderInterruptores(nomeDoProduto)){
                    cout<<"Interruptor vendido.\n";
                    removerInterruptores(reguser);
                    g.salvarNoArquivoInterruptoresDR(reguser);
                    removerInterruptoresVendidos(reguser);
                    g.salvarNoArquivoInterruptoresDRVendidos(reguser);
                }
                else{
                    cout<<"Não foi possivel vender.\n";
                }
                system("pause");
                system("cls");
                break;
    	    case 27:
    	    	exibiMenuInterruptores();
            	cout<<"Digite o nome do produto a ser removido : ";
	            cin >>nomeDoProduto;

	            if(g.removerInterruptoresDoEstoque(nomeDoProduto)){
	                cout<<"Produto removido.\n";
	                removerInterruptores(reguser);
                    g.salvarNoArquivoInterruptoresDR(reguser);
	            }
	            else{
	                cout<<"Não foi realizar essa operação.\n";
	            }

	            system("pause");
	            system("cls");
                break;
    	    case 28:
    	    	exibiMenuInterruptores();
				g.exibiAsInterruptoresDisponiveis();
                system("pause");
                system("cls");
                break;
    	    case 29:
    	    	exibiMenuInterruptores();
				cout<<"Digite o nome do disjuntor a ser pesquisado ";
                cin >>nomeDoProduto;

                g.exibiNomesDosInterruptores(nomeDoProduto);

                system("pause");
                system("cls");
                break;
    	    case 30:
    	    	exibiMenuInterruptores();
				g.exibiInterruptoresVendidos();

                system("pause");
                system("cls");
                break;
            case 31:
            	system("cls");
      			exibiAoAdm();
				cout << "insira o valor da potencia mensal kwh: "<< endl;
				cin >> potencia;
				cout << "insira o valor do gasto mensal em R$: "<< endl;
				cin >> gasto;
				calcula.setPotencia(potencia);
				calcula.setGasto(gasto);
				cout << "Economia anual: R$ " << calcula.economia_anual() << endl;
				system("pause");
				system("cls");
    	        break;
            case 32:
            	system("cls");
      			exibiAoAdm();
				cout << "insira o valor da potencia mensal kwh: "<< endl;
				cin >> potencia;
				cout << "insira o valor do gasto mensal em R$: "<< endl;
				cin >> gasto;
				calcula.setPotencia(potencia);
				calcula.setGasto(gasto);
				cout << "Quantidade de paineis necessarios: " << calcula.quantidade_de_paineis_necessarios() << endl;
				system("pause");
				system("cls");
    	        break;
			case 33:
				system("cls");
      			exibiAoAdm();
				cout << "insira o valor da potencia mensal kwh: "<< endl;
				cin >> potencia;
				cout << "insira o valor do gasto mensal em R$: "<< endl;
				cin >> gasto;
				calcula.setPotencia(potencia);
				calcula.setGasto(gasto);
				cout << "Area minima para instalação:  " << calcula.area_minima() <<"  metros quadrados"<<endl;
				system("pause");
				system("cls");
    	        break;
			case 34:
				return;
            default:
                cout << "Opção inválida" << endl;
                break;
        }
    }while(op=!0);
}

void calculaPlacasEBaterias()
{
	int opcaoDoCliente;
	do{
    	system("cls");
        exibiAoClienteOP();
        Empresa_Solar calcula;
        if(opcaoDoCliente == 0){
            break;
        }
		cout<< "\n\nEscolha uma opção: ";
		cin>> opcaoDoCliente;
		switch(opcaoDoCliente)
			{
	
		       case 1:
	      		    system("cls");
	      			exibiAoCliente();
	     	 	    g.exibiAsBateriasDisponiveis();
	            	system("pause");
	            	system("cls");
	                break;
		       case 2:
		       		system("cls");
		       		exibiAoCliente();
	      	  	  	g.exibiAsBateriasDisponiveis();
					cout<<"\nDigite o nome da marca: ";
					cin >>nomeDoProduto;
					if(g.venderBaterias(nomeDoProduto)){
	                    cout<<"Bateria vendida.\n";
	                    removerBaterias(reguser);
	    				g.salvarNoArquivoBaterias(reguser);
	    				removerBateriasVendidas(reguser);
	    				g.salvarNoArquivoBateriasVendidas(reguser);
	                }
	                else{
	                    cout<<"Não foi vender a bateria.\n";
	                }
	
	                system("pause");
	                system("cls");
	                break;
		       case 3:
		       		system("cls");
		       		exibiAoCliente();
		       		g.exibiPlacas_Solares();
	                system("pause");
	                system("cls");
	                break;
	           case 4:
	           		system("cls");
	           		exibiAoCliente();
	                cout<<"\nDigite o nome ou marca: ";
	                cin >>nomeDoProduto;
	                if(g.venderPlacas_Solares(nomeDoProduto)){
	                    cout<<"Placa Solar vendida.\n";
	                    removerPlacas(reguser);
	                    g.salvarNoArquivoPlacas_Solares(reguser);
	                    removerPlacasVendidas(reguser);
	                    g.salvarNoArquivoPlacas_SolaresVendidas(reguser);
	                }
	                else{
	                    cout<<"Não foi possivel vender a placa.\n";
	                }
	
	                system("pause");
	                system("cls");
	                break;   
			   case 5:
			   		system("cls");
			   		exibiAoCliente();
	   		 		g.exibiInversores();
	                system("pause");
	                system("cls");
	                break;
			   case 6:
			   		system("cls");
			   		exibiAoCliente();
			   		g.exibiInversores();
	                cout<<"\nDigite o nome ou marca: ";
	                cin >>nomeDoProduto;
	                if(g.venderInversores(nomeDoProduto)){
	                    cout<<"Inversor vendida.\n";
	                    removerInversores(reguser);
	                    g.salvarNoArquivoInversores(reguser);
	                    removerInversoresVendidos(reguser);
	                    g.salvarNoArquivoInversoresVendidos(reguser);
	                }
	                else{
	                    cout<<"Não foi possivel vender o inversor.\n";
	                }
	
	                system("pause");
	                system("cls");
	                break;
			   case 7:
			   		system("cls");
			   		exibiAoCliente();
			   		g.exibiAsInterruptoresDisponiveis();
	                system("pause");
	                system("cls");
	                break;
			   case 8:
			   		system("cls");
			   		exibiAoCliente();
			   		g.exibiAsInterruptoresDisponiveis();
	
	                cout<<"\nDigite o nome ou marca: ";
	                cin >>nomeDoProduto;
	                if(g.venderInterruptores(nomeDoProduto)){
	                    cout<<"Interruptor vendido.\n";
	                    removerInterruptores(reguser);
	                    g.salvarNoArquivoInterruptoresDR(reguser);
	                    removerInterruptoresVendidos(reguser);
	                    g.salvarNoArquivoInterruptoresDRVendidos(reguser);
	                }
	                else{
	                    cout<<"Não foi possivel vender.\n";
	                }
	                system("pause");
	                system("cls");
	                break;
			   case 9:
			   		system("cls");
			   		exibiAoCliente();
			   		g.exibiDisjuntorDisponiveis();
	                system("pause");
	                system("cls");
	                break;
			   case 10:
			   		system("cls");
			   		exibiAoCliente();
			   		g.exibiDisjuntorDisponiveis();
	
	                cout<<"\nDigite o nome ou marca: ";
	                cin >>nomeDoProduto;
	                if(g.venderDisjuntor(nomeDoProduto)){
	                    cout<<"Disjuntor vendido.\n";
	                    removerDisjuntores(reguser);
	                    g.salvarNoArquivoDisjuntoreDifResDDR(reguser);
	                    removerDisjuntoresVendidos(reguser);
	                    g.salvarNoArquivoDisjuntoreDifResDDRVendidos(reguser);
	                }
	                else{
	                    cout<<"Não foi possivel vender o inversor.\n";
	                }
	
	                system("pause");
	                system("cls");
	                break; 
			   case 11:
			   		system("cls");
			   		exibiAoCliente();
					cout << "insira o valor do gasto mensal em R$: "<< endl;
					cin >> gasto;
					calcula.setGasto(gasto);
					cout << "Economia anual: R$ " << calcula.economia_anual() << endl;
					system("pause");
					system("cls");
	    	        break;
			   case 12:
			   		system("cls");
			   		exibiAoCliente();
					cout << "insira o valor da potencia mensal kwh: "<< endl;
					cin >> potencia;
					calcula.setPotencia(potencia);
					cout << "Quantidade de paineis necessarios: " << calcula.quantidade_de_paineis_necessarios() << endl;
					system("pause");
					system("cls");
					break;
			   case 13:
			   		system("cls");
			   		exibiAoCliente();
			   		cout << "insira o valor da potencia mensal kwh: "<< endl;
					cin >> potencia;
					cout << "insira o valor do gasto mensal em R$: "<< endl;
					cin >> gasto;
					calcula.setPotencia(potencia);
					cout << "Area minima para instalação:  " << calcula.area_minima() <<"  metros quadrados"<<endl;
					system("pause");
					system("cls");
	    	        break;								
		       case 0:
		       		return;
		       default:
	                  system("cls");
	                  escolhaErrada();
	                  system("pause");
	                  system("cls");
	                  calculaPlacasEBaterias();
	        }
	}while(opcaoDoCliente=!0);		
}
void exibiMenuBaterias(){
	cout<<"___________________________________________________________________________________________________________________________ " <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                         |"<<endl;
    cout<<"|                                            (Administrador)                                                               |"<<endl;
	cout<<"|                                               BATERIAS                                                                   |"<<endl;
	cout<<"|                                                OPÇÃO: "<< opcao << "                                                                  |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________________|" <<endl;
}
void exibiMenuPlacas(){
	cout<<"___________________________________________________________________________________________________________________________ " <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                         |"<<endl;
    cout<<"|                                            (Administrador)                                                               |"<<endl;
	cout<<"|                                             PLACAS SOLARES                                                               |"<<endl;
	cout<<"|                                                OPÇÃO: "<< opcao << "                                                                  |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________________|" <<endl;
}
void exibiMenuDisjuntores(){
	cout<<"___________________________________________________________________________________________________________________________ " <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                         |"<<endl;
    cout<<"|                                            (Administrador)                                                               |"<<endl;
	cout<<"|                                              DISJUNTORES                                                                 |"<<endl;
	cout<<"|                                                OPÇÃO: "<< opcao << "                                                                 |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________________|" <<endl;
}
void exibiMenuInterruptores(){
	cout<<"___________________________________________________________________________________________________________________________ " <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                         |"<<endl;
    cout<<"|                                            (Administrador)                                                               |"<<endl;
	cout<<"|                                              INTERRUPTORES                                                               |"<<endl;
	cout<<"|                                                OPÇÃO: "<< opcao << "                                                                 |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________________|" <<endl;
}
void exibiAoCliente(){
	cout<<" ____________________________________________________________________________________________________________________________" <<endl;
    cout<<"|                                               Empresa De Energia Solar                                                     |" <<endl;
    cout<<"|                                                    (Administrador)                                                         |" <<endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                          \\                  /                         \\                  /                                 |" << endl;
    cout<<"|                           \\                /                           \\                /                                  |"<< endl;
    cout<<"|                            \\              /                             \\              /                                   |" << endl;
    cout<<"|                             \\            /                               \\            /                                    |" << endl;
    cout<<"|                              \\          /                                 \\          /                                     |" << endl;
    cout<<"|                               \\        /                                   \\        /                                      |" << endl;
    cout<<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
    cout<<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
    cout<<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout<<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
    cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                           |"<<endl;
    cout<<"|                                            (Cliente)                                                                       |"<<endl;
	cout<<"|                                           Seja bem-vindo!                                                                  |"<<endl;
	cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
}
void exibiAoClienteOP(){
	cout<<" ____________________________________________________________________________________________________________________________" <<endl;
    cout<<"|                                               Empresa De Energia Solar                                                     |" <<endl;
    cout<<"|                                                    (Administrador)                                                         |" <<endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                          \\                  /                         \\                  /                                 |" << endl;
    cout<<"|                           \\                /                           \\                /                                  |"<< endl;
    cout<<"|                            \\              /                             \\              /                                   |" << endl;
    cout<<"|                             \\            /                               \\            /                                    |" << endl;
    cout<<"|                              \\          /                                 \\          /                                     |" << endl;
    cout<<"|                               \\        /                                   \\        /                                      |" << endl;
    cout<<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
    cout<<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
    cout<<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout<<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
    cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                           |"<<endl;
    cout<<"|                                            (Cliente)                                                                       |"<<endl;
	cout<<"|                                           Seja bem-vindo!                                                                  |"<<endl;
    cout<<"|_______________________________________.________________________________________.___________________________________________|" <<endl;
    cout<<"|              ESTOQUE                  |               CÁLCULOS                 |                                           |" <<endl;
    cout<<"|                                       |                                        |                                           |" << endl;
    cout<<"| 1. EXIBIR BATERIAS DISPONÍVEIS        | 11. CALCULAR     ECONOMIA     ANUAL    |                                           |" << endl;
    cout<<"| 2. COMPRAR BATERIAS                   | 12. CALCULAR QUANTIDADE  DE PAINÉIS    |                                           |" << endl;
    cout<<"| 3. EXIBIR PLACAS SOLARES DISPONÍVEIS  |     NECESSÁRIOS                        |                                           |" << endl;
    cout<<"| 4. COMPRAR PLACAS SOLARES             | 13. CALCULAR ÁREA MÍNIMA               |                                           |" << endl;
    cout<<"| 5. EXIBIR  INVERSORES                 | 0. SAIR                                |                                           |" << endl;
    cout<<"| 6. COMPRAR INVERSORES                 |                                        |                                           |" << endl;
    cout<<"| 7. EXIBIR INTERRUPTORES               |                                        |                                           |" << endl;
    cout<<"| 8. COMPRAR INTERRUPTORES              |                                        |                                           |" << endl;
    cout<<"| 9. EXIBIR DISJUNTORES DR E IDR        |                                        |                                           |" << endl;
    cout<<"|10. COMPRAR DISJUNTORES DR E IDR       |                                        |                                           |" << endl;
    cout<<"|                                       |                                        |                                           |" << endl;
    cout<<"|                                       |                                        |                                           |"<<endl ;
    cout<<"|_______________________________________|________________________________________|___________________________________________|" ;
}

void menuPrincipal(){
	cout<<" ____________________________________________________________________________________________________________________________" <<endl;
    cout<<"|                                               Empresa De Energia Solar                                                     |" <<endl;
    cout<<"|                                                    (Administrador)                                                         |" <<endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                          \\                  /                         \\                  /                                 |" << endl;
    cout<<"|                           \\                /                           \\                /                                  |"<< endl;
    cout<<"|                            \\              /                             \\              /                                   |" << endl;
    cout<<"|                             \\            /                               \\            /                                    |" << endl;
    cout<<"|                              \\          /                                 \\          /                                     |" << endl;
    cout<<"|                               \\        /                                   \\        /                                      |" << endl;
    cout<<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
    cout<<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
    cout<<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout<<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
    cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
	cout<<"|                Por Favor Informe o seu Tipo de Usuário:                                                                    |" << endl;
	cout<<"|                1.Administrador                                                                                             |" << endl;
	cout<<"|                2.Cliente                                                                                                   |" << endl;
	cout<<"|                0.Fechar                                                                                                    |" << endl;
	cout<<"|                Digite sua escolha abaixo :                                                                                 |" << endl;
	cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
	cout<<"                      Aqui: "; cin >> opcao;
	cout<< endl;
}

void administrador(){
      system("cls");
      cout <<" ____________________________________________________________________________________________________________________________" <<endl;
      cout <<"|                                               Empresa De Energia Solar                                                     |" <<endl;
	  cout <<"|                                                    (Administrador)                                                         |" <<endl;
	  cout <<"| ___________________________________________________________________________________________________________________________|" <<endl;
      cout <<"|                          \\                  /                         \\                  /                                 |" << endl;
      cout <<"|                           \\                /                           \\                /                                  |"<< endl;
      cout <<"|                            \\              /                             \\              /                                   |" << endl;
      cout <<"|                             \\            /                               \\            /                                    |" << endl;
      cout <<"|                              \\          /                                 \\          /                                     |" << endl;
      cout <<"|                               \\        /                                   \\        /                                      |" << endl;
      cout <<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
      cout <<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
      cout <<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
      cout <<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
	  cout <<"| ___________________________________________________________________________________________________________________________|" <<endl;
      cout <<"|               1.LOGIN                                                                                                      |" << endl;
      cout <<"|               2.REGISTRO                                                                                                   |" << endl;
	  cout <<"|               3.ESQUECI A SENHA (ou) NOME DE USUÁRIO (Em desenvolvimento)                                                  |" << endl;
	  cout <<"|               0.VOLTAR AO MENU INICIAL:                                                                                    |" << endl;
      cout <<"|       		  Digite sua escolha abaixo :                                                                                  |" << endl;
	  cout <<"|                                                                                                                            |" << endl;
      cout <<"|____________________________________________________________________________________________________________________________|" <<endl;
      cout<<"                      Aqui: "; cin>> opcaoDesejadaDoMenu;

      cout<<endl;
}
void cliente(){
	system("cls");
	
	cout<<" ____________________________________________________________________________________________________________________________" <<endl;
    cout<<"|                                               Empresa De Energia Solar                                                     |" <<endl;
    cout<<"|                                                                                                                            |" <<endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                          \\                  /                         \\                  /                                 |" << endl;
    cout<<"|                           \\                /                           \\                /                                  |"<< endl;
    cout<<"|                            \\              /                             \\              /                                   |" << endl;
    cout<<"|                             \\            /                               \\            /                                    |" << endl;
    cout<<"|                              \\          /                                 \\          /                                     |" << endl;
    cout<<"|                               \\        /                                   \\        /                                      |" << endl;
    cout<<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
    cout<<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
    cout<<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout<<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
    cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
	cout<<"|                                    Empresa De Energia Solar                                                                |"<< endl;
	cout<<"|                                             (Cliente)                                                                      |"<< endl;
	cout<<"|                                    1.LOGIN                                                                                 |" << endl;
	cout<<"|                                    2.REGISTRO                                                                              |" << endl;
	cout<<"|                                    3.ESQUECI A SENHA (ou) NOME DE USUÁRIO                                                  |" << endl;
	cout<<"|                                    0.VOLTAR AO MENU INICIAL                                                                |" << endl;
	cout<<"|                                    Digite sua escolha abaixo :                                                             |" << endl;
	cout<<"|                                                                                                                            |" << endl;
	cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
	cout<<"                                     OPÇÃO:"; cin>> opcaoDesejadaDoMenu2;

	cout<<endl;
}
void escolhaErrada(){
	system("cls");
		cout<<" ____________________________________________________________________________________________________________________________" <<endl;
    cout<<"|                                               Empresa De Energia Solar                                                     |" <<endl;
    cout<<"|                                                                                                                            |" <<endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                          \\                  /                         \\                  /                                 |" << endl;
    cout<<"|                           \\                /                           \\                /                                  |"<< endl;
    cout<<"|                            \\              /                             \\              /                                   |" << endl;
    cout<<"|                             \\            /                               \\            /                                    |" << endl;
    cout<<"|                              \\          /                                 \\          /                                     |" << endl;
    cout<<"|                               \\        /                                   \\        /                                      |" << endl;
    cout<<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
    cout<<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
    cout<<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout<<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
    cout<<"|____________________________________________________________________________________________________________________________|" <<endl;
	cout<<" Desculpe, você digitou a escolha errada. Por favor, tente novamente" << endl;
	system("pause");
	system("cls");
}

void menuAdm() {
	cout << " ___________________________________________________________________________________________________________________________ " <<endl;
	cout << "                                                Empresa De Energia Solar                                                    |" <<endl;
	cout << "                                                    (Administrador)                                                         |" <<endl;
	cout << " ___________________________________________________________________________________________________________________________|" <<endl;
    cout << "                              \\                  /                     \\                  /                                 |" << endl;
    cout << "                               \\                /                       \\                /                                  |"<< endl;
    cout << "                                \\              /                         \\              /                                   |" << endl;
    cout << "                                 \\            /                           \\            /                                    |" << endl;
    cout << "                                  \\          /                             \\          /                                     |" << endl;
    cout << "                                   \\        /                               \\        /                                      |" << endl;
    cout << "     _______   _______              \\      /       _______   _______         \\      /           _______   _______           |" << endl;
    cout << "    |       | |       |              \\    /       |       | |       |         \\    /           |       | |       |          |" << endl;
    cout << "    |   O   | |   O   |               \\  /        |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout << "    |_______| |_______|                \\/         |_______| |_______|           \\/             |_______| |_______|          |" << endl;
	cout << " _______________________________________|________________________________________|__________________________________________|" <<endl;
    cout << "|Sobre Baterias:                        | Sobre Inversores:                      | Sobre Interruptores:                     |" <<endl;
    cout << "|1. Adicionar bateria ao estoque        | 13. Adicionar inversores ao estoque    | 25. Adicionar interruptores ao estoque   |" << endl;
    cout << "|2. Vender bateria                      | 14. Vender   inversores                | 26. Vender   interruptores               |" << endl;
    cout << "|3. Remover bateria do estoque          | 15. Remover   inversor  do  estoque    | 27. Remover   interruptor  do  estoque   |" << endl;
    cout << "|4. Exibir baterias disponíveis         | 16. Exibir  inversores  disponíveis    | 28. Exibir  interruptores  disponíveis   |" << endl;
    cout << "|5. Pesquisar nomes das baterias        | 17. Pesq.  nomes  dos   inversores     | 29. Pesq.  nomes  dos   interruptores    |" << endl;
    cout << "|6. Exibir baterias vendidas            | 18. Exibir    inversores   vendidos    | 30. Exibir    interruptores   vendidos   |" << endl;
    cout << "|Sobre Placas Solares:                  | Sobre Dijuntores:                      | Mais  opções   sobre    engenharia:      |" << endl;
    cout << "|7. Adicionar placa solar ao estoque    | 19. Adicionar dijuntores ao estoque    | 31. Calcular     economia     anual      |" << endl;
    cout << "|8. Vender placa solar                  | 20. Vender   dijuntores                | 32. Calcular  quantidade  de painéis     |" << endl;
    cout << "|9. Remover placa solar do estoque      | 21. Remover   dijuntor  do  estoque    | necessários                              |" << endl;
    cout << "|10. Exibir placas solares disponíveis  | 22. Exibir  dijuntores  disponíveis    | 33. Calcular área mínima                 |" << endl;
    cout << "|11. Pesq. por nome das placas solares  | 23. Pesq.  nomes  dos   dijuntores     | 34. Sair                                 |" << endl;
    cout << "|12. Exibir placas solares vendidas     | 24. Exibir    dijuntores  vendidos     |                                          |"<<endl ;
    cout << "|_______________________________________|________________________________________|__________________________________________|" ;
}

void exibiAoAdm(){
	cout<<" ____________________________________________________________________________________________________________________________" <<endl;
    cout<<"|                                               Empresa De Energia Solar                                                     |" <<endl;
    cout<<"|                                                    (Administrador)                                                         |" <<endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                          \\                  /                         \\                  /                                 |" << endl;
    cout<<"|                           \\                /                           \\                /                                  |"<< endl;
    cout<<"|                            \\              /                             \\              /                                   |" << endl;
    cout<<"|                             \\            /                               \\            /                                    |" << endl;
    cout<<"|                              \\          /                                 \\          /                                     |" << endl;
    cout<<"|                               \\        /                                   \\        /                                      |" << endl;
    cout<<"|     _______   _______          \\      /           _______   _______         \\      /           _______   _______           |" << endl;
    cout<<"|    |       | |       |          \\    /           |       | |       |         \\    /           |       | |       |          |" << endl;
    cout<<"|    |   O   | |   O   |           \\  /            |   O   | |   O   |          \\  /            |   O   | |   O   |          |" << endl;
    cout<<"|    |_______| |_______|            \\/             |_______| |_______|           \\/             |_______| |_______|          |" << endl;
    cout<<"| ___________________________________________________________________________________________________________________________|" <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                         |"<<endl;
    cout<<"|                                            (Administrador)                                                               |"<<endl;
	cout<<"|                                            Seja bem-vindo!                                                               |"<<endl;
	cout<<"|                                                                                                                          |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________________|" <<endl;
}


void exibiMenuInversores(){
	cout<<"___________________________________________________________________________________________________________________________ " <<endl;
    cout<<"|                                         Empresa De Energia Solar                                                         |"<<endl;
    cout<<"|                                            (Administrador)                                                               |"<<endl;
	cout<<"|                                               INVERSORES                                                                 |"<<endl;
	cout<<"|                                                OPÇÃO: "<< opcao << "                                                                 |"<<endl;
	cout<<"|__________________________________________________________________________________________________________________________|" <<endl;
}
void removerBaterias(string reguser){
	  string nomePasta = "arquivos/" + reguser + "BateriasEstoque.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerPlacas(string reguser){
	  string nomePasta = "arquivos/" + reguser + "PlacasEstoque.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerInversores(string reguser){
	  string nomePasta = "arquivos/" + reguser + "Inversores.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerInterruptores(string reguser){
	  string nomePasta = "arquivos/" + reguser + "InterruptoresEstoque.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerDisjuntores(string reguser){
	  string nomePasta = "arquivos/" + reguser + "DisjuntoresEstoque.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerBateriasVendidas(string reguser){
	  string nomePasta = "arquivos/" + reguser + "BateriasVendidas.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()){
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerPlacasVendidas(string reguser){
	  string nomePasta = "arquivos/" + reguser + "PlacasVendidas.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerInversoresVendidos(string reguser){
	  string nomePasta = "arquivos/" + reguser + "InversoresVendidos.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerDisjuntoresVendidos(string reguser){
	  string nomePasta = "arquivos/" + reguser + "DisjuntoresVendidos.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void removerInterruptoresVendidos(string reguser){
	  string nomePasta = "arquivos/" + reguser + "InterruptoresVendidos.txt";
      ofstream arquivo(nomePasta.c_str(), ios::trunc);
	  if (arquivo.is_open()) {
	    arquivo.close();
	  } else {
	    cout << "Erro ao abrir o arquivo" << endl;
	  }
}
void abreEstoqueBaterias(string reguser){
	string nomePasta = "arquivos/" + reguser + "BateriasEstoque.txt";
    ifstream arquivo(nomePasta.c_str());
	if (arquivo.is_open()) {
	    while(arquivo>>u>>p>>c>>x>>y)
	    {
	        nomeDoProduto=u, codigoBarras=p, precoDoProduto=c, capacidadeDeArmazenamento=x, voltagemDeSaida=y;

			obj1.setNomeDoProduto(nomeDoProduto);
	        obj1.setPrecoDoProduto(precoDoProduto);
	        obj1.setCodigoBarras(codigoBarras);
	        obj1.setCapacidadeDeArmazenamento(capacidadeDeArmazenamento);
	        obj1.setVoltagemDeSaida(voltagemDeSaida);
	        g.adicionaBaterias(obj1);
	    }
	    arquivo.close();
	}
}
void abreEstoquePlacas(string reguser){
	string nomePasta = "arquivos/" + reguser + "PlacasEstoque.txt";
    ifstream arquivo(nomePasta.c_str());
	if (arquivo.is_open()) {
	    while(arquivo>>u>>p>>c>>x)
	    {
	            nomeDoProduto=u, codigoBarras=p, precoDoProduto=c, capacidadeDeGeracaoWatts=x;

				obj2.setNomeDoProduto(nomeDoProduto);
	            obj2.setPrecoDoProduto(precoDoProduto);
	            obj2.setCodigoBarras(codigoBarras);
	            obj2.setCapacidadeDeGeracaoWatts(capacidadeDeGeracaoWatts);
	            g.adicionaPlacas_Solares(obj2);
	    }
	    arquivo.close();
	}
}
void abreEstoqueInversores(string reguser){
	string nomePasta = "arquivos/" + reguser + "Inversores.txt";
    ifstream arquivo(nomePasta.c_str());
	if (arquivo.is_open()) {
	    while(arquivo>>u>>p>>c>>x)
	    {
	            nomeDoProduto=u, codigoBarras=p, precoDoProduto=c, tensaoSuportada=x;

				obj3.setNomeDoProduto(nomeDoProduto);
	            obj3.setCodigoBarras(codigoBarras);
	            obj3.setPrecoDoProduto(precoDoProduto);
	            obj3.setTensaoSuportada(tensaoSuportada);
	            g.adicionaInversores(obj3);
	    }
	    arquivo.close();
	}
}
void abreEstoqueInterruptores(string reguser){
	string nomePasta = "arquivos/" + reguser + "InterruptoresEstoque.txt";
    ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>p>>c>>x>>w)
	    {
	            nomeDoProduto=u, codigoBarras=p, precoDoProduto=c, tensaoSuportada=x, amperesSuportado=w;

				obj4.setNomeDoProduto(nomeDoProduto);
	            obj4.setCodigoBarras(codigoBarras);
	            obj4.setPrecoDoProduto(precoDoProduto);
	            obj4.setTensaoSuportada(tensaoSuportada);
	            obj4.setAmperesSuportado(amperesSuportado);
	            g.adicionaInterruptores(obj4);
	    }
	    arquivo.close();
	}
}

void abreEstoqueDisjuntores(string reguser){
	string nomePasta = "arquivos/" + reguser + "DisjuntoresEstoque.txt";
    ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>p>>c>>x>>w>>z)
	    {
	            nomeDoProduto=u, codigoBarras=p, precoDoProduto=c, tensaoSuportada=x, amperesSuportado=w, idrTrueFalse=z;

				obj5.setNomeDoProduto(nomeDoProduto);
	            obj5.setPrecoDoProduto(precoDoProduto);
	            obj5.setCodigoBarras(codigoBarras);
	            obj5.setTensaoSuportada(tensaoSuportada);
	            obj5.setAmperesSuportado(amperesSuportado);
	            obj5.setIdrTrueFalse(idrTrueFalse);
	            g.adicionaDisjuntor(obj5);
	    }
	    arquivo.close();
	}
}
void abreEstoqueBateriasVendidas(string reguser){
	string nomePasta = "arquivos/" + reguser + "BateriasVendidas.txt";
    ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>c)
	    {
	            nomeDoProduto=u, precoDoProduto=c;

				obj1.setNomeDoProduto(nomeDoProduto);
	            obj1.setPrecoDoProduto(precoDoProduto);
	            g.adicionaBateriasVendidas(obj1);
	    }
	    arquivo.close();
	}
}
void abreEstoquePlacasVendidas(string reguser){
	string nomePasta = "arquivos/" + reguser + "PlacasVendidas.txt";
    ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>c)
	    {
	            nomeDoProduto=u, precoDoProduto=c;

				obj2.setNomeDoProduto(nomeDoProduto);
	            obj2.setPrecoDoProduto(precoDoProduto);
	            g.adicionaPlacas_SolaresVendidas(obj2);
	    }
	    arquivo.close();
	}

}
void abreEstoqueInversoresVendidos(string reguser){
	string nomePasta = "arquivos/" + reguser + "InversoresVendidos.txt";
    ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>c)
	    {
	            nomeDoProduto=u, precoDoProduto=c;

				obj3.setNomeDoProduto(nomeDoProduto);
	            obj3.setPrecoDoProduto(precoDoProduto);
	            g.adicionaInversoresVendidos(obj3);
	    }
	    arquivo.close();
	}
}
void abreEstoqueInterruptoresVendidos(string reguser){
	string nomePasta = "arquivos/" + reguser + "InterruptoresVendidos.txt";
	ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>c)
	    {
	            nomeDoProduto=u, precoDoProduto=c;

				obj4.setNomeDoProduto(nomeDoProduto);
	            obj4.setPrecoDoProduto(precoDoProduto);
	            g.adicionaInterruptoresDRVendidos(obj4);
	    }
	    arquivo.close();
	}
}
void abreEstoqueDisjuntoresVendidos(string reguser){
	string nomePasta = "arquivos/" + reguser + "DisjuntoresVendidos.txt";
	ifstream arquivo(nomePasta.c_str());
    if (arquivo.is_open()) {
	    while(arquivo>>u>>c)
	    {
	            nomeDoProduto=u, precoDoProduto=c;

				obj5.setNomeDoProduto(nomeDoProduto);
	            obj5.setPrecoDoProduto(precoDoProduto);
	            g.adicionaDisjuntoreDifResDDRVendidos(obj5);
	    }
	    arquivo.close();
	}
}
void registroADM() {
    system("cls");
    exibiAoAdm();
    cout << "Faça seu registro abaixo (Administrador)\n\n\n";
    cout << "Escolha o seu nome de usuário: ";
    cin >> reguser;
    cout << "\nEscolha sua senha: ";
    cin >> regpass;
    cout << "\nInforme o seu código Administrador: ";
    cin >> codeadm;
    string nomeUsuario = reguser;
    string nomePasta = "arquivos/" + nomeUsuario + ".txt";
    ofstream arquivo(nomePasta.c_str(), ios::app);

    if (arquivo.is_open()) {
        arquivo << reguser << ' ' << regpass << ' ' << codeadm << endl;
        arquivo.close();
        system("cls");
        cout << "\nRegistrado com sucesso!\n";
    } else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}
void registroCl(){
        system("pause");
        system("cls");
        exibiAoCliente();
        cout<<"                                          Escolha o seu nome de usuário :";
        cin>>reguser;
        cout<<"\n                                          Escolha sua senha :";
        cin>>regpass;

        ofstream reg("Arquivos/textoCliente.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistraado com sucesso!\n";

}
void loginADM(){
    system("cls");
    exibiAoAdm();
    cout<<"Por favor coloque os seguintes detalhes abaixo"<<endl;
    cout<<"NOME :";
    cin>>reguser;
    cout<<"SENHA :";
    cin>>regpass;
    cout<<"CÓDIGO DE ADMINISTRADOR :";
    cin>>codeadm;

    string nomeUsuario = reguser;
    string nomePasta = "arquivos/" + nomeUsuario + ".txt";
    ifstream reg;
	reg.open(nomePasta.c_str());
	if (reg.is_open()) {
        string u, p, x;
        bool retorna = false;
        while(reg >> u >> p >> x)
        {
            if(u==reguser && p==regpass && x==codeadm)
            {
                retorna=1;
                system("cls");
            }
        }
        reg.close();
        if(retorna==1)
        {
            exibiAoAdm();
            cout<<"\nOlá "<<user<<"\nSUCESSO DE LOGIN\nEstamos felizes por você estar aqui.\nObrigado por fazer login\n";
            system("pause");
            system("cls");
            g.apagarVetorBaterias();
			g.apagarVetorBateriasVendidas();
			g.apagarVetorDisjuntores();
		    g.apagarVetorDisjuntoresVendidos();
		    g.apagarVetorInterruptor();
			g.apagarVetorInterruptorVendido();
			g.apagarVetorInversor();
			g.apagarVetorInversorVendido();
			g.apagarVetorPlacas();
			g.apagarVetorPlacasVendidas();
            abreEstoqueBaterias(reguser);
            abreEstoquePlacas(reguser);
            abreEstoqueInversores(reguser);
		    abreEstoqueBateriasVendidas(reguser);
		    abreEstoquePlacasVendidas(reguser);
		    abreEstoqueInversoresVendidos(reguser);
		    abreEstoqueInterruptores(reguser);
		    abreEstoqueDisjuntores(reguser);
		    abreEstoqueDisjuntoresVendidos(reguser);
		    abreEstoqueInterruptoresVendidos(reguser);
            principal();
            cin.get();
            cin.get();
        }
        else
        {
        	system("cls");
            exibiAoAdm();
            system("cls");
            cout<<"\nERRO DE LOGIN\nVerifique seu nome de usuário, senha ou código de administrador. \n";
            system("pause");
            system("cls");
        }
    } else {
    	system("cls");
        exibiAoAdm();
        cout<<"\nERRO DE LOGIN\nVerifique seu nome de usuário, senha ou código de administrador. \n";
        system("pause");
        system("cls");
    }
}
void loginCl(){
        system("cls");
        exibiAoCliente();
        cout<<"Por favor coloque os seguintes detalhes abaixo"<<endl;
        cout<<"NOME :";
        cin>>user;
        cout<<"SENHA :";
        cin>>pass;

        fstream input("Arquivos/textoCliente.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        retorna2=1;
                        system("cls");
                }
        }
        input.close();
        if(retorna2==1)
        {
        		exibiAoCliente();
                cout<<"\nOlá "<<user<<"\nEstamos felizes por você estar aqui.\nObrigado por fazer login\n";
                system("pause");
				system("cls");
				calculaPlacasEBaterias();
				cin.get();


        }
        else
        {
                cout<<"\nERRO DE LOGIN\nVerifique seu nome de usuário e senha\nVocê talvez não tenha feito o registro!\n\n\n\n";
                system("pause");
                system("cls");
                cin.get();

        }
}
void pesquisa(){
	do{
        system("pause");
        system("cls");
        cout<<"======================================================================================================================\n\n\n";
        cout<<"                                         Vamos te ajudar agora!                                  \n\n\n ";
        cout<<"=================================       Empresa De Energia Solar        ==============================================\n\n";
        cout<<"Esquecido? Estamos aqui para ajudar\n";
        cout<<"1.Pesquise seu id por nome de usuário"<<endl;
        cout<<"2.Pesquise seu id por senha"<<endl;
        cout<<"3.Menu principal"<<endl;
        cout<<"Digite sua escolha abaixo :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp, sq;
                        cout<<"========================================================================================================================\n\n\n";
				        cout<<"                                            Faça seu registro abaixo                                      \n\n\n ";
				        cout<<"=================================       Empresa De Energia Solar        ===============================================\n\n";
                        cout<<"\nDigite seu nome de usuário que cadastrou:";
                        cin>>searchuser;

                        fstream searchu("Arquivos/textoADM.txt");
                        while(searchu>>su>>sp>>sq)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nConta encontrada\n";
                                cout<<"\nSua senha e "<<sp;
                                cout<<"\nSeu código de ADM "<<sq;
                                cin.get();
                                cin.get();
                                system("pause");
                                system("cls");

                        }
                        else
                        {
                        		cout<<"=======================================================================================================================\n\n\n";
						        cout<<"                                          Tente novamente!                                       \n\n\n ";
						        cout<<"=================================       Empresa De Energia Solar        ===============================================\n\n";
                                cout<<"\nDesculpe, seu userID não foi encontrado em nosso banco de dados\n";
                                cout<<"\nPor favor, entre em contato com o administrador do sistema para obter mais detalhes \n";
                                cin.get();
                                cin.get();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"=======================================================================================================================\n\n\n";
				        cout<<"                                        Recuperar senha definida                                      \n\n\n ";
				        cout<<"=================================       Empresa De Energia Solar        ===============================================\n\n";
                        cout<<"\nDigite a senha lembrada:";
                        cin>>searchpass;

                        fstream searchp("Arquivos/textoADM.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                        		cout<<"========================================================================================================================\n\n\n";
						        cout<<"                                               Parabéns!                                    \n\n\n ";
						        cout<<"=================================       Empresa De Energia Solar        ===============================================\n\n";
                                cout<<"\nSua senha é encontrada no banco de dados \n";
                                cout<<"\nseu id é : "<<su2;
                                cin.get();
                                cin.get();
                                system("pause");
                                system("cls");
                        }
                        else
                        {

                        		cout<<"=======================================================================================================================\n\n\n";
						        cout<<"                                             Tente novamente!                                            \n\n\n ";
						        cout<<"=================================       Empresa De Energia Solar        ===============================================\n\n";
                                cout<<"Desculpe, não encontramos sua senha em nosso banco de dados \n";
                                cout<<"\nPor favor, entre em contato com seu administrador para obter mais informações\n";
                                cin.get();
                                cin.get();

                        }

                        break;
                }
                case 3:
                {
                        cin.get();
                }
                default:
                		cout<<"========================================================================================================================\n\n\n";
				        cout<<"                                            Tente novamente!                                      \n\n\n ";
				        cout<<"=================================       Empresa De Energia Solar        ===============================================\n\n";
                        cout<<"Desculpe, você digitou a escolha errada. Por favor, tente novamente"<<endl;
                        pesquisa();
        }
	}while(op=!0);
}
