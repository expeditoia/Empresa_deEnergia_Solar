#include "Estoque.hpp"

using namespace std;
string k2, m2, n2, o2;
float l2;

bool Estoque::adicionaPlacas_Solares(Placas p2){
    if(placasEmEstoque.empty()){
        placasEmEstoque.push_back(p2);
        return true;
    }
    else{
        for(int i = 0; i < placasEmEstoque.size(); i++){
            if(placasEmEstoque[i].getPrecoDoProduto() == p2.getPrecoDoProduto()){
                return false;
            }
        }
        placasEmEstoque.push_back(p2);
        return true;
    }
}
bool Estoque::removerPlacas_SolaresDoEstoque(string pesquisa){
    if(placasEmEstoque.empty()){
        return false;
    }
    else{
        for(int i = 0; i < placasEmEstoque.size(); i++){
            if(placasEmEstoque[i].getNomeDoProduto() == pesquisa){
                placasEmEstoque.erase(placasEmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
bool Estoque::venderPlacas_Solares(string pesquisa){
    if(placasEmEstoque.empty()){
        return false;
    }
    else{

        Placas vende;

        std::cout<<"\n\n";

        for(int i = 0; i < placasEmEstoque.size(); i++){
            if(placasEmEstoque[i].getNomeDoProduto() == pesquisa){
                vende = placasEmEstoque[i];
                placasVendidas.insert(placasVendidas.begin(), vende);
                placasEmEstoque.erase(placasEmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
void Estoque::exibiPlacas_Solares(){
    if(placasEmEstoque.empty()){
        std::cout<<"\n- Estoque vazio\n";
    }
    else{
        cout<<"\n";
        for(int i = 0; i < placasEmEstoque.size(); i++){
            cout<<"Marca do produto: "<<placasEmEstoque[i].getNomeDoProduto()<<endl;
			cout<<"O preço do produto:"<<placasEmEstoque[i].getPrecoDoProduto()<<endl;
			cout<<"Código de barras: "<<placasEmEstoque[i].getCodigoBarras()<<endl;
			cout<<"Capacidade de geração Watts: " <<placasEmEstoque[i].getCapacidadeDeGeracaoWatts()<<"\n";
        	cout<< "\n"<< endl;
		}
    }

}
void Estoque::exibiNomesDasPlacas_Solares(string pesquisa){
    if(placasEmEstoque.empty()){
        std::cout<<"\n- não existe\n";
    }
    else{
        bool a = false;
        std::cout<<"\n";
        for(int i = 0; i < placasEmEstoque.size(); i++){
            if(placasEmEstoque[i].getNomeDoProduto() == pesquisa){
                cout<<"Marca do produto: "<<placasEmEstoque[i].getNomeDoProduto()<<endl;
				cout<<"O preço do produto:"<<placasEmEstoque[i].getPrecoDoProduto()<<endl;
				cout<<"Código de barras: "<<placasEmEstoque[i].getCodigoBarras()<<endl;
				cout<<"Capacidade de geração Watts: " <<placasEmEstoque[i].getCapacidadeDeGeracaoWatts()<<"\n";
	        	cout<< "\n"<< endl;                
				a = true;
                break;
            }
        }
        if(a == false){
            cout<<"\n- não existe\n";
        }
    }
}
void Estoque::exibiPlacas_SolaresVendidas() {
    if(placasVendidas.empty()) {
        cout << "\n- Não há placas solares vendidas\n";
    } else {
        double totalVendas = 0.0;
        int quantidadeVendas = placasVendidas.size();
        cout << "\n";
        for(int i = 0; i < quantidadeVendas; i++) {
            cout << "- Produto vendido: " << endl;
            cout << "Marca do produto: " << placasVendidas[i].getNomeDoProduto() << endl;
            cout << "O preço do produto: " << placasVendidas[i].getPrecoDoProduto() << endl;
            totalVendas += placasVendidas[i].getPrecoDoProduto();
            cout << "\n" << endl;
        }
        double mediaVendas = ceil((totalVendas / quantidadeVendas) * 100.0) / 100.0;
        cout << "Quantidade de placas solares vendidas: " << quantidadeVendas << endl;
        cout << "Média de preço das placas solares vendidas: R$" << mediaVendas << endl;
        cout << "Soma do dinheiro total em vendas: R$" << totalVendas << endl;
    }
}
void Estoque::salvarNoArquivoPlacas_Solares(string reguser){
	string nomePasta = "arquivos/" + reguser + "PlacasEstoque.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < placasEmEstoque.size(); i++){
	        k2 = placasEmEstoque[i].getNomeDoProduto();
			l2 = placasEmEstoque[i].getPrecoDoProduto();
			m2 = placasEmEstoque[i].getCodigoBarras();
			n2 = placasEmEstoque[i].getCapacidadeDeGeracaoWatts();
			arquivo<<k2<<' '<<l2<<' '<<m2<<' '<<n2<< "\n";
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
    } 
}
void Estoque::salvarNoArquivoPlacas_SolaresVendidas(string reguser){
	string nomePasta = "arquivos/" + reguser + "PlacasVendidas.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < placasVendidas.size(); i++){
	        k2 = placasVendidas[i].getNomeDoProduto();
			l2 = placasVendidas[i].getPrecoDoProduto();
			arquivo<<k2<<' '<<l2<< "\n";
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
    } 
}
bool Estoque::adicionaPlacas_SolaresVendidas(Placas p2){
    if(placasVendidas.empty()){
        placasVendidas.push_back(p2);
        return true;
    }
    else{
        for(int i = 0; i < placasVendidas.size(); i++){
            if(placasVendidas[i].getPrecoDoProduto() == p2.getPrecoDoProduto()){
                return false;
            }
        }
        placasVendidas.push_back(p2);
        return true;
    }
}

void Estoque::apagarVetorPlacas() {
    placasEmEstoque.clear();
}
void Estoque::apagarVetorPlacasVendidas() {
    placasVendidas.clear();
}