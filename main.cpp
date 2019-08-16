#include <iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
struct Estudiante {
    string nombre;
};
bool isPrime(long int prime);
long int calculateE( long int t );
long int greatestCommonDivisor( long int e, long int t );
long int calculateD( long int e, long int t );
long int encrypt( long int i, long int e, long int n );
long int decrypt(long int i, long int d, long int n );
void escribir(char cuenta[15],char mesa[15]);
int grabarRegistro( FILE * f, Estudiante r);


int main( )
{

    int matriz[30][72]={};
    ifstream archivo;
    string contenido;
    char arch[15]= "arch.txt";
    FILE * F;
    F = fopen("Alumnos", wb);
    if ((F = fopen("Alumnos", wb)) == NULL) {
        return;
    }
    //archivo.open(arch,ios::out);
    //if(!archivo.is_open())
   // {
    //    cout << "Error, no se ha podido abrir el programa";
    //    return 0;
   // }
   /* while(!archivo.eof()){
        getline(archivo,contenido);
        fila++;
        if((fila>=4 && fila <=23)||(fila>=29 && fila<=38))
            {
                if((contenido[69]=='0') || (contenido[69]=='1') || (contenido[69]=='2') || (contenido[69]=='3') || (contenido[69]=='4') || (contenido[69]=='5') || (contenido[69]=='6') || (contenido[69]=='7') || (contenido[69]=='8') || (contenido[69]=='9'))
                {
                    // mi numero tiene dos digitos
                    votos[filasinternas]=(contenido[69]-48)*10+(contenido[70]-48)+votos[filasinternas];
                }
                else
                {
                    votos[filasinternas]=(contenido[70]-48)+votos[filasinternas];
                }
                if(i==4)
                {
                    for(int j=0;j<69;j++)
                    {
                        candidatos[filasinternas][j]=contenido[j];
                    }
                    centena=votos[filasinternas]/100;
                    decena=(votos[filasinternas]-centena*100)/10;
                    unidad=votos[filasinternas]-centena*100-decena*10;
                    candidatos[filasinternas][69]=centena+48;
                    candidatos[filasinternas][70]=decena+48;
                    candidatos[filasinternas][71]=unidad+48;
                }
                filasinternas++;
            }
        }
        archivo.close();
    }*/
    long int p, q, n, t, e, d;

    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));

    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));

    bool flag;

    string msg;
    cout << "Welcome to RCA program" << endl;

    do
    {
        cout << "Enter a Prime number  p : ";
        cin >> p;
        flag = isPrime( p );

        if ( flag == false )
        {
            cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
    } while ( flag == false );

    do
    {
        cout << "Enter a Prime number  q :";
        cin >> q;
        flag = isPrime( q );

        if ( flag == false )
        {
            cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
    } while ( flag == false);

    // 2. Вычисляется их произведение n = p ⋅ q, которое называется модулем.
    n = p * q;
    cout << "\nResult of computing n = p*q = " << n << endl;

    // 3. Вычисляется значение функции Эйлера от числа n: φ(n) = (p−1)⋅(q−1)
    t = ( p - 1 ) * ( q - 1 );
    cout << "Result of computing Euler's totient function:\t t = " << t << endl;

    // 4. Выбирается целое число e ( 1 < e < φ(n) ), взаимно простое со значением функции Эйлера (t)
    //	  Число e называется открытой экспонентой
    e = calculateE( t );
    cout << "E = " << e;
    // 5. Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))
    d = calculateD( e, t );

    // 6. Пара {e, n} публикуется в качестве открытого ключа RSA
    cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;

    // 7. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
    cout << "RSA private key is (n = " << n << ", d = " << d << ")" << std::endl;

    cout << "\nEnter Message to be encryped:" << std::endl;

    // there is a newline character left in the input stream, so we use ignore()
    cin.ignore();

    getline( cin, msg );

    cout << "\nThe message is: " << msg << endl;


    // encryption

    for (long int i = 0; i < msg.length(); i++){
        encryptedText[i] = encrypt( msg[i], e, n);
    }

    cout << "\nTHE ENCRYPTED MESSAGE IS:" << std::endl;
    char frase[15] = {};
    for ( long int i = 0; i < msg.length(); i++ ){
        cout<<(char)encryptedText[i] ;
        frase[i] = (char)encryptedText[i];
    }
    Estudiante e = new Estudiante();
    strcpy(e.nombre, frase);
    escribir(frase,arch);
    grabarRegistro( F, TipoRegistro r);

    //decryption

    for (long int i = 0; i < msg.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }

    cout << "\n\nTHE DECRYPTED MESSAGE IS:" << std::endl;

    for (long int i = 0; i < msg.length(); i++)
    {
        printf( "%c", (char)decryptedText[i] );
    }
    cout << std::endl << std::endl;
    archivo.close();
    archivo.open("arch.txt");
    int cont[100];
    while(!archivo.eof()){
        getline(archivo,contenido);
        cout<<"              CONTENIDO ENCRIPTADO: "<<contenido<<endl;
        for (long int i = 0; i < 10; i++){
            cont[i] = decrypt(contenido[i], d, n);
        }
        cout<<"              CONTENIDO DESENCRIPTADO 1: ";
        for (long int i = 0; i < 10; i++)
        {
            printf( "%c", (char)cont[i] );
        }
        /* for (int jk = 0; jk < contenido.length(); jk++){
            if(contenido[contenido.length()-jk] != 'k'){
                contenido[contenido.length()-jk] = ' ';
            }
        }
        cout<<"              CONTENIDO DESENCRIPTADO 2: "<<contenido<<endl;*/
        cout<<"  --------------------- "<<endl;
    }
    archivo.close();
    //system("PAUSE");
    return 0;
}

bool isPrime( long int prime){
    long int i, j;

    j = (long int)sqrt((long double)prime);

    for ( i = 2; i <= j; i++)
    {
        if ( prime % i == 0 )
        {
            return false;
        }
    }

    return true;
}

long int calculateE( long int t ){
    // Выбирается целое число e ( 1 < e < t ) // взаимно простое со значением функции Эйлера (t)

    long int e;

    for ( e = 2; e < t; e++ )
    {
        if (greatestCommonDivisor( e, t ) == 1 )
        {
            return e;
        }
    }

    return -1;
}

long int greatestCommonDivisor( long int e, long int t ){
    while ( e > 0 )
    {
        long int myTemp;

        myTemp = e;
        e = t % e;
        t = myTemp;
    }

    return t;
}

long int calculateD( long int e, long int t){
    // Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))

    long int d;
    long int k = 1;

    while ( 1 )
    {
        k = k + t;

        if ( k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }

}

long int encrypt( long int i, long int e, long int n ){
    long int current, result;
    current = i - 97;
    result = 1;
    for ( long int j = 0; j < e; j++ ){
        result = result * current;
        result = result % n;
    }
    return result;
}

long int decrypt(long int i, long int d, long int n){
    long int current, result;
    current = i;
    result = 1;
    for ( long int j = 0; j < d; j++ ){
        result = result * current;
        result = result % n;
    }
    return result + 97;
}

void escribir(char cuenta[15],char mesa[15]){
    int i;
    ofstream archivo;
    archivo.open(mesa,ios::app);
    for(i=0;i<15;i++){
        archivo<<cuenta[i];
    }
    archivo<<endl;
}

int grabarRegistro( FILE * f, TipoRegistro r){
    return fwrite(&r, sizeof(r) , 1, f);
}
