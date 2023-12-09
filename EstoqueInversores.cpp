#include "Estoque.hpp"

using namespace std;

string k, m, n, o;
float l;

bool Estoque::adicionaInversores(Inversores p3){
    if(inversoresEmEstoque.empty()){
        inversoresEmEstoque.push_back(p3);
        return true;
    }
    else{
        for(int i = 0; i < inversoresEmEstoque.size(); i++){
            if(inversoresEmEstoque[i].getPrecoDoProduto() == p3.getPrecoDoProduto()){
                return false;
            }
        }
        inversoresEmEstoque.push_back(p3);
        return true;
    }
}
bool Estoque::removerInversoresDoEstoque(string pesquisa){
    if(inversoresEmEstoque.empty()){
        return false;
    }
    else{
        for(int i = 0; i < inversoresEmEstoque.size(); i++){
            if(inversoresEmEstoque[i].getNomeDoProduto() == pesquisa){
                inversoresEmEstoque.erase(inversoresEmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
bool Estoque::venderInversores(string pesquisa){
    if(inversoresEmEstoque.empty()){
        return false;
    }
    else{

        Inversores vende;

        std::cout<<"\n\n";

        for(int i = 0; i < inversoresEmEstoque.size(); i++){
            if(inversoresEmEstoque[i].getNomeDoProduto() == pesquisa){
                vende = inversoresEmEstoque[i];
                inversoresVendidos.insert(inversoresVendidos.begin(), vende);
                inversoresEmEstoque.erase(inversoresEmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
void Estoque::exibiInversores(){
    if(inversoresEmEstoque.empty()){
        std::cout<<"\n- Estoque vazio\n";
    }
    else{
        cout<<"\n";
        for(int i = 0; i < inversoresEmEstoque.size(); i++){
            cout<<"Marca do produto: "<<inversoresEmEstoque[i].getNomeDoProduto()<<endl;
			cout<<"O preço do produto:"<<inversoresEmEstoque[i].getPrecoDoProduto()<<endl;
			cout<<"Código de barras: "<<inversoresEmEstoque[i].getCodigoBarras()<<endl;
			cout<<"Capacidade de: " <<inversoresEmEstoque[i].getTensaoSuportada()<<"\n";
        	cout<< "\n"<< endl;
		}
    }

}
void Estoque::exibiNomesDasInversores(string pesquisa){
    if(inversoresEmEstoque.empty()){
        std::cout<<"\n- não existe\n";
    }
    else{
        bool a = false;
        std::cout<<"\n";
        for(int i = 0; i < inversoresEmEstoque.size(); i++){
            if(inversoresEmEstoque[i].getNomeDoProduto() == pesquisa){
                cout<<"Marca do produto: "<<inversoresEmEstoque[i].getNomeDoProduto()<<endl;
				cout<<"O preço do produto:"<<inversoresEmEstoque[i].getPrecoDoProduto()<<endl;
				cout<<"Código de barras: "<<inversoresEmEstoque[i].getCodigoBarras()<<endl;
				cout<<"Capacidade de: " <<inversoresEmEstoque[i].getTensaoSuportada()<<"\n";
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
void Estoque::exibiInversoresVendidos() {
    if(inversoresVendidos.empty()) {
        cout << "\n- Não há inversores vendidos\n";
    } else {
        double totalVendas = 0.0;
        cout << "\n";
        for(int i = 0; i < inversoresVendidos.size(); i++) {
            cout << "- Produto vendido: " << endl;
            cout << "Marca do produto: " << inversoresVendidos[i].getNomeDoProduto() << endl;
            cout << "O preço do produto: " << inversoresVendidos[i].getPrecoDoProduto() << endl;
            totalVendas += inversoresVendidos[i].getPrecoDoProduto();
            cout << "\n" << endl;
        }
        int quantidadeVendas = inversoresVendidos.size();
        double mediaVendas = totalVendas / quantidadeVendas;
        cout << "Quantidade de vendas: " << quantidadeVendas << endl;
        cout << "Média das vendas: R$" << fixed << setprecision(2) << ceil(mediaVendas * 100) / 100 << endl;
        cout << "Soma do dinheiro total em vendas: R$" << totalVendas << endl;
    }
}
void Estoque::salvarNoArquivoInversores(string reguser){
	string nomePasta = "arquivos/" + reguser + "Inversores.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < inversoresEmEstoque.size(); i++){
	        k = inversoresEmEstoque[i].getNomeDoProduto();
			l = inversoresEmEstoque[i].getPrecoDoProduto();
			m = inversoresEmEstoque[i].getCodigoBarras();
			n = inversoresEmEstoque[i].getTensaoSuportada();
			arquivo<<k<<' '<<l<<' '<<m<<' '<<n<< "\n";
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
    } 
}
void Estoque::salvarNoArquivoInversoresVendidos(string reguser){
	string nomePasta = "arquivos/" + reguser + "InversoresVendidos.txt";
	ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
	    for(int i = 0; i < inversoresVendidos.size(); i++){
	        k = inversoresVendidos[i].getNomeDoProduto();
	    	l = inversoresVendidos[i].getPrecoDoProduto();
			arquivo<<k<<' '<<l<< "\n";
	    }
	    arquivo.close();
	} else {
        cout << "Erro ao abrir o arquivo!" << endl;
	}   
}
bool Estoque::adicionaInversoresVendidos(Inversores p3){
    if(inversoresVendidos.empty()){
        inversoresVendidos.push_back(p3);
        return true;
    }
    else{
        for(int i = 0; i <inversoresVendidos.size(); i++){
            if(inversoresVendidos[i].getPrecoDoProduto() == p3.getPrecoDoProduto()){
                return false;
            }
        }
        inversoresVendidos.push_back(p3); 
        return true;
    }
}
void Estoque::apagarVetorInversor() {
    inversoresEmEstoque.clear();
}
void Estoque::apagarVetorInversorVendido() {
    inversoresVendidos.clear();
}