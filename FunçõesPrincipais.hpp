#ifndef LoginESenha_H
#define LoginESenha_H
using namespace std;
class Login
{
    public:	 
	  void menuAdm();
	  void exibiAoAdm();
	  void principal();
	  void calculaPlacasEBaterias();
	  void exibiMenuPlacas();
	  void exibiMenuBaterias();
	  void exibiMenuInversores(); 
	  void exibiAoCliente();
	  void escolhaErrada();	
	     	
	  void removerBaterias(string reguser);
      void removerPlacas(string reguser);
      void removerInterruptores(string reguser);
      void removerDisjuntores(string reguser);
      void removerInversores(string reguser);
      
      void removerDisjuntoresVendidos(string reguser);
      void removerInterruptoresVendidos(string reguser);
	  void removerBateriasVendidas(string reguser);
      void removerPlacasVendidas(string reguser);
	  void removerInversoresVendidos(string reguser); 
	  	 	
	  void abreEstoquePlacasVendidas(string);
	  void abreEstoqueBateriasVendidas(string);
	  void abreEstoqueInversoresVendidos(string);
	  void abreEstoqueDisjuntoresVendidos(string);
	  void abreEstoqueInterruptoresVendidos(string);
	  
	  void abreEstoqueBaterias(string);
	  void abreEstoquePlacas(string);
	  void abreEstoqueInversores(string);
	  void abreEstoqueInterruptores(string);
	  void abreEstoqueDisjuntores(string);
	     	
      void loginADM();
      void loginCl();
      void pesquisa();
      void registroADM();
      void registroCl();
      void menuPrincipal();
	  void administrador();
	  void cliente();
	  
};
#endif