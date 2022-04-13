# AED
Aca se subiran todos los trabajos practicos correspondientes a la Materia "Algoritmo y Estructura de Datos" en la comision K1253 año 2022, correspondientes al alumno Lucas Tomas Barrera(N° de legajo: 2098660)


// Instrucciones para la instalacion y configuracion de nuestro IDE y el compilador

Para los trabajos de la Materia se utilizara como IDE "Eclipse IDE for C/C++ Developers"(https://www.eclipse.org/downloads/packages/release/2022-03/r/eclipse-ide-cc-developers) y como compilador utilizaremos el Equatios(http://www.equation.com/servlet/equation.cmd?fa=home), que al momento de instalar se debera instalar en la carpeta "C:\MinGW"

Para configurar correctamente el IDE, una vez abierto:
Iremos en la parte superior a Windows -> General -> WorkSpace
                                                    |---> Text File encording -> Other ->
                                                    |---> Next text file line delimiter -> Other -> Unix

Luego nos desplazamos a C/C++ -> Build 
                                 |-> Enviroment -> ADD ----> Y comolocaremos como name: "Path" y value: "C:\MinGW\bin"                                                                                    |-> New C/C++ proyect wizard -> desabilitaremos la opcion que dice "Show proyect types (...)" y seleccionaremos en Toolchain "MinGW GCC"
                                 
Y ya tendremos listo y configurado nuestro IDE y nuestro compilador para su correcto uso         

// Resolucion del trabajo 0

En la primera línea de codigo ubicaremos la libreria "iostream" llamandola con #include<>, esta libreria nos permitira la entrada y salidas 

Luego colocaremos el "using namespace std" para definir todos los comandos estandares, por ejemplo el cout; en caso de no utilizarlo tendriamos que escribir en la linea de codigo que contenga el cout "std::cout<<;"

Ya determinado eso empezaremos con la funcion principal la cual la denominamos int main()

En ella incluiremos la linea de codigo "cout<<"HelloWorld!";" para que como salida de la funcion tengamos un mensaje diciendo "HelloWorld!"

Luego apretamos ctrl+b y por ultimo ejecutamos el programa con F5 y tendremos una linea de codigo diciendo "HelloWorld!"
