
int ingresoDatos(char nombres[][50], int tiempoF[], int pantallas[], int tarjetaR[], int memorias[], int discoD[] , int cont);
int compararProdcutos(char nombres[][50], char comparacion[], int cont);
void tabla1(char nombres[][50], int cont, int tiempoF[5], int pantallas[5], int tarjetaR[5], int memorias[5], int discoD[5]);
void EditarProducto (char nombres[][50], int tiempoF[], int pantallas[], int tarjetaR[], int memorias[], int discoD[], int posicion );
void eliminar(char nombre[][50], int tiempoF[], int cantidad[], int productos[], int posicion, int cont);
void abastecer(int *pantallasF, int *tarjetaRF, int *memoriasF, int *discoDF);
void pedidos(char nombres[][50], int cont, int cantidad[]);
void tablaInventario(int pantallasF, int tarjetaRF, int memoriasF, int discoDF);
int tiempo(int tiempoF[], int cont, int cantidad[]);
int inventarioVacio(int cantidad[], int cont);
