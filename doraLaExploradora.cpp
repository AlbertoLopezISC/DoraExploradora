#include <cstdio>
#include <cstdlib>
#include <cstring>

int busquedaCamino(char**, int, int);
int busca(char**, int, int, int, int);

int main(int argc, char const *argv[])
{
	int renglones = 0;
	int columnas = 0;

	bool datos_correctos = false;

	do{
		printf("dame el numero de renglones y columnas: \n");
		scanf("%d %d", &renglones, &columnas);
		if(renglones >= 3 && renglones <= 51 && columnas >= 3 && columnas <= 51)
			datos_correctos = true;
		else{
			printf("Datos incorrectos, vuelve a intentarlo\n");
			datos_correctos = false;
			continue;
		}

		char **tablero = new char * [renglones];
		for(int i = 0; i < renglones; i++){
			tablero[i] = new char[columnas];
		}

		int i = 0;
		do{
			printf("Ingresa los caracteres linea por linea\n");
			scanf("%s", tablero[i]);
			if(strlen(tablero[i]) != columnas ){
				printf("los caracteres introducidos no cumplen con las columnas\n");
				continue;
			}
			i++;
		}while(i<renglones);

		datos_correctos = true;

		busquedaCamino(tablero, renglones, columnas);
		printf("\n\n\n");
		for(int i = 0; i < renglones; i++){
			printf("%s\n",tablero[i] );
		}

	}while(!datos_correctos);
	


	return 0;
}

int busquedaCamino(char **tablero, int n, int m){
	int ini_x, ini_y;
	for(int i = 0; i < n; i++ ){
		for(int j = 0; j < m; j++){
			if(tablero[i][j] == '#'){
				ini_x = i;
				ini_y = j;
			}
		}
	}
	busca(tablero, ini_x, ini_y, n, m);
	return 0;
}

int busca(char **tablero, int x, int y, int n, int m){
	tablero[x][y] = '#';
		if(x-1 >= 0)
			if(tablero[x-1][y] == '.')
				busca(tablero, x-1, y, n, m);
		if(y+1 < m)
			if(tablero[x][y+1] == '.')
				busca(tablero, x, y+1, n, m);
		if(x+1 < n)
			if(tablero[x+1][y] == '.')
				busca(tablero, x+1, y, n, m);
		if(y-1 >= 0)
			if(tablero[x][y-1] == '.')
				busca(tablero, x, y-1, n, m);
	return 0;
}