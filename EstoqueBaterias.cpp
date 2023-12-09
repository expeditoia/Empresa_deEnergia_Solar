#include "Estoque.hpp"

using namespace std;
string k1, m1, n1, o1;
float l1;
bool Estoque::adicionaBaterias(Baterias p){
    if(bateriasEmEstoque.empty()){
        bateriasEmEstoque.push_back(p);
        return true;
    }
    else{
        for(int i = 0; i < bateriasEmEstoque.size(); i++){
            if(bateriasEmEstoque[i].getPrecoDoProduto() == p.getPrecoDoProduto()){
                return false;
            }
        }
        bateriasEmEstoque.push_back(p);
        return true;
    }
}
bool Estoque::venderBaterias(string pesquisa){
    if(bateriasEmEstoque.empty()){
        return false;
    }
    else{

        Baterias aux;
        cout<<"\n\n";
        for(int i = 0; i < bateriasEmEstoque.size(); i++){
            if(bateriasEmEstoque[i].getNomeDoProduto() == pesquisa){
                aux = bateriasEmEstoque[i];
                bateriasVendidas.insert(bateriasVendidas.begin(), aux);
                bateriasEmEstoque.erase(bateriasEmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
bool Estoque::removerBateriasDoEstoque(string pesquisa){
    if(bateriasEmEstoque.empty()){
        return false;
    }
    else{
        for(int i = 0; i < bateriasEmEstoque.size(); i++){
            if(bateriasEmEstoque[i].getNomeDoProduto() == pesquisa){
                bateriasEmEstoque.erase(bateriasEmEstoque.begin()+i);
                return true;
            }
        }
        return false;
    }
}
void Estoque::exibiAsBateriasDisponiveis(){
    if(bateriasEmEstoque.empty()){
        cout<<"\n- Estoque vazio\n";
    }
    else{
		cout<<"\n";
        for(int i = 0; i < bateriasEmEstoque.size(); i++){
            cout<<"Marca do produto: "<<bateriasEmEstoque[i].getNomeDoProduto()<<endl;
			cout<<"O preço do produto:"<<bateriasEmEstoque[i].getPrecoDoProduto()<<endl;
			cout<<"Código de barras: "<<bateriasEmEstoque[i].getCodigoBarras()<<endl;
			cout<<"Capacidade de armazenamento: "<<bateriasEmEstoque[i].getCapacidadeDeArmazenamento()<<endl;
			cout<<"Voltagem de saída:"<<bateriasEmEstoque[i].getVoltagemDeSaida();
			cout<< "\n" <<endl;
        }
    }

}
void Estoque::exibiNomesDasBaterias(string pesquisa){
    if(bateriasEmEstoque.empty()){
        cout<<"\n- não existe!\n";
    }
    else{
        bool a = false;
        cout<<"\n";
        for(int i = 0; i < bateriasEmEstoque.size(); i++){
            if(bateriasEmEstoque[i].getNomeDoProduto() == pesquisa){
                cout<<"Marca do produto: " <<bateriasEmEstoque[i].getNomeDoProduto()<<endl;
				cout<<"O preço do produto:"<<bateriasEmEstoque[i].getPrecoDoProduto()<<endl;
				cout<<"Código de barras: "<<bateriasEmEstoque[i].getCodigoBarras()<<endl;
				cout<<"Capacidade de armazenamento: "<<bateriasEmEstoque[i].getCapacidadeDeArmazenamento()<<endl;
				cout<<"Voltagem de saída:"<<bateriasEmEstoque[i].getVoltagemDeSaida()<<"\n";
				cout<< "\n" <<endl;
                a = true;
                break;
            }
        }
        if(a == false){
            cout<<"\n- não existe!\n";
        }
    }
}


void Estoque::exibiBateriasVendidas() {
	if(bateriasVendidas.empty()) {
		cout << "\n- Não há baterias vendidas\n";
	} else {
		double totalVendas = 0.0;
		cout << "\n";
		for(int i = 0; i < bateriasVendidas.size(); i++) {
		cout << "- Produto vendido: " << endl;
		cout << "Marca do produto: " << bateriasVendidas[i].getNomeDoProduto() << endl;
		cout << "O preço do produto: " << bateriasVendidas[i].getPrecoDoProduto() << endl;
		totalVendas += bateriasVendidas[i].getPrecoDoProduto();
		cout << "\n" << endl;
		}
		double mediaVendas = totalVendas / bateriasVendidas.size();
		cout << "Quantidade de vendas: " << bateriasVendidas.size() << endl;
		cout << "Média de vendas: R$" << fixed << setprecision(2) << ceil(mediaVendas*100)/100 << endl;
		cout << "Soma do dinheiro total em vendas: R$" << totalVendas << endl;
	}
}
void Estoque::salvarNoArquivoBaterias(string reguser){
    string nomePasta = "arquivos/" + reguser + "BateriasEstoque.txt";
    ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
        for(int i = 0; i < bateriasEmEstoque.size(); i++){
            k1 = bateriasEmEstoque[i].getNomeDoProduto();
			l1 = bateriasEmEstoque[i].getPrecoDoProduto();
			m1 = bateriasEmEstoque[i].getCodigoBarras();
			n1 = bateriasEmEstoque[i].getCapacidadeDeArmazenamento();
			o1 = bateriasEmEstoque[i].getVoltagemDeSaida();
            arquivo << k1 << ' ' << l1 << ' ' << m1 << ' ' << n1 << ' ' << o1<<'\n';
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
}
void Estoque::salvarNoArquivoBateriasVendidas(string reguser){
    string nomePasta = "arquivos/" + reguser + "BateriasVendidas.txt";
    ofstream arquivo(nomePasta.c_str(), ios::app);
    if (arquivo.is_open()) {
        for(int i = 0; i < bateriasVendidas.size(); i++){
            k1 =  bateriasVendidas[i].getNomeDoProduto();
			l1 =  bateriasVendidas[i].getPrecoDoProduto();
            arquivo << k1 << ' ' << l1<<'\n';
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo!" << endl;
    }
    
}

bool Estoque::adicionaBateriasVendidas(Baterias p){
    if(bateriasVendidas.empty()){
        bateriasVendidas.push_back(p);
        return true;
    }
    else{
        for(int i = 0; i < bateriasVendidas.size(); i++){
            if( bateriasVendidas[i].getPrecoDoProduto() == p.getPrecoDoProduto()){
                return false;
            }
        }
        bateriasVendidas.push_back(p);
        return true;
    }
}
void Estoque::apagarVetorBaterias() {
    bateriasEmEstoque.clear();
}
void Estoque::apagarVetorBateriasVendidas() {
    bateriasVendidas.clear();
}