#include <iostream>
using namespace std;

const char*	Wildcard(const char* wild, const char* src);

int main()
{
	cout << "\"as*te*o\" en \",mnaswiteo\" = " << Wildcard("as*te*o", ",mnaswiteolapoe");
	cin.get();
	return 0;
}
const char*	Wildcard(const char* wild, const char* src)
{	
	////////////////////////////////////////////////////////////////
	//	Esta funcion busca un patron regular wild en el char* src. Y devuelve lo que haya
	//	a partir de ahi. Usa el caracter * como comodin. Si no encuentra nada devuelve NULL, ojo con eso!
	//	Por ejemplo "as*te*o" dara true en ",mnaswiteo" pero false en ",mnaswitio"
	////////////////////////////////////////////////////////////////
	bool matching = false;
	unsigned int s = 0, w = 0;
	unsigned int sizeW = strlen(wild);
	unsigned int sizeS = strlen(src);

	for(s = 0; s < sizeS; s++)
	{
		if(wild[w] == '*')
		{
			return Wildcard(&wild[w+1], &src[s]);
		}

		if(wild[w] == src[s])
		{
			matching = true;
			w++;
		}
		else
		{
			matching = false;
			w = 0;
		}
		if(w == sizeW) return &src[s+1];	// Devuelve a partir del ultimo caracter que tiene match INCLUIDO
	}										// usar &src[s+1] si se quiere devolver excluyendo ese ultimo char
	return NULL;
}