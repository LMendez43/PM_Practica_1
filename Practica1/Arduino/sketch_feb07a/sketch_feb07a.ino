#define LED 9     //El LED esta conectado en el pin 9 
#define LDR 0     //El LDR esta conectador en el pin A0
#define POT 2     //El Potenciometro en el pin A2

int luz = 0;       
int valor_sensor = 0;       
int valor_limite = 0;  //Este valor hara que el LED cambie de estado a una determinada luminosidad (podeis con distintos valores para ajustar la sensibilidad)
int mo=0;
int mp=0; 

void setup() {      //Configuracion de los pin como entrada o salida 
  Serial.begin(9600);    
  pinMode(LED,OUTPUT);
  pinMode(LDR,INPUT);
  pinMode(POT,INPUT);
  
}

void loop ()  //Configuracion de los valores del LDR
{
  valor_sensor = analogRead(LDR);
  valor_limite = analogRead(POT); 
  luz = (5.0 * valor_sensor * 100.0)/1024.0; 
  mo = map(luz,280,500,0,100);
  mp = map(valor_limite,0,1024,0,100); 
  Serial.print(luz);  
  Serial.println(" Luz");
  Serial.print(valor_limite);  
  Serial.println(" Valor Limite");
  Serial.print(mo);
  Serial.println(" % de oscuridad");
  Serial.print(mp);
  Serial.println(" % de limite");
  Serial.println("");

  delay(1000);                       
  
  if (luz <= valor_limite)   //Si el valor de luz es menor o igual que el valor limite
  {
    digitalWrite (LED, LOW);  //El led se apaga
  }
  if (luz > valor_limite)   //Si es mayor que el valor limite
  {
    digitalWrite (LED, HIGH);  //El led se eniende
  }
}
