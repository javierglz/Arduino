
int izqAv = 5; 
int izqRv = 6; 
int derAv = 9; 
int derRv = 10; 
int vel = 200; // Velocidad de los motores (0-255)
int trigger=13; 
int echo=12; 
float dist, res;

void setup()  { 
  pinMode(derAv, OUTPUT);
  pinMode(derRv, OUTPUT);
  pinMode(izqAv, OUTPUT);
  pinMode(izqRv, OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
Serial.begin(9600);
 } 
 
void loop()  { 
  
 res=ultra();
    Serial.println(res);
    
   if(res<= 20 && res>1)
   {
    analogWrite(derAv, 0);  // Detiene los  2 Motores
    analogWrite(izqAv, 0); 
    delay (1000);
    
    reversa();
    int azar =random(2);
      if(azar==0)   {derecha();  }
      else          {izquierda();}
    
    }
   else
   
   {
    avanza();
    }

    
//apagado();
                
}


//*************************************



int avanza(){

 analogWrite(derAv, vel);  
 analogWrite(izqAv, vel); 
    
}    

int izquierda(){
  analogWrite(derAv, vel);  // Av Derecho  x segundos
  delay (1700);
  analogWrite(derAv, 0);  // Av Derecho se detiene
  delay (1000);
}
    

int derecha(){
   analogWrite(izqAv, vel);  // Av izq x segundos
   delay (1700);
   analogWrite(izqAv, 0);  // Av izq se detiene
   delay (1000);
}

int reversa(){
 analogWrite(derRv, vel);  // Reversa x segundos
 analogWrite(izqRv, vel);
 digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
 delay (2000);
 analogWrite(derRv, 0);  // detiene motores x segundos
 analogWrite(izqRv, 0);         
 delay (1000);
 digitalWrite(7,LOW);
 digitalWrite(8,LOW);
}

int girad(){
analogWrite(izqAv, vel);  // Reversa x segundos
   analogWrite(derRv, vel); 
   delay (2600);         

   analogWrite(izqAv, 0);  // detiene motores x segundos
   analogWrite(derRv, 0);
  delay (1000);

}

int girai(){
   analogWrite(derAv, vel);  // Reversa x segundos
   analogWrite(izqRv, vel); 
   delay (2600);         
   analogWrite(derAv, 0);  // detiene motores x segundos
   analogWrite(izqRv, 0);
   delay (1000);
}


int apagado(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
     delay (10000);
  }

 float ultra()
  {
  digitalWrite(trigger,LOW);
  delayMicroseconds(15);         // Inicialización del sensor para que se estabilice.
  digitalWrite(trigger,HIGH);   // Enviamos una señal activando la... trigger accionador o disparo
  delayMicroseconds(10);        // salida trigger durante 10 microsegundos
  digitalWrite(trigger,LOW);    // Desactivamos la señal del trigger para evitar interferencias.
  // Adquirimos los datos y convertimos la medida a cm
  int tiempo=pulseIn(echo,HIGH);      // Este resultado está en microsegundos. 
                                // Cuando la lectura del pin sea HIGH medirá 
                                // el tiempo que transcurre hasta que sea LOW en useg
  dist = float(tiempo/58.2);               // Se hace la conversión a centímetros (o .017) en base al formula vel*tiempo
  return (dist);
  }      
