/*
╔═════════════════════════════════════════════════╗
║    __    __________                             __  _______ ____             ║
║   / /   / ____/ __ \   ____ _   _____  _____   / / / / ___// __ )            ║
║  / /   / __/ / / / /  / __ \ | / / _ \/ ___/  / / / /\__ \/ __  |            ║
║ / /___/ /___/ /_/ /  / /_/ / |/ /  __/ /     / /_/ /___/ / /_/ /             ║
║/_____/_____/_____/   \____/|___/\___/_/      \____//____/_____/              ║
║                                         _      __         ___ __  _          ║
║                            ___ ___ ____(_)__ _/ / ___ ___/ (_) /_(_)__  ___  ║
║                           (_-</ -_) __/ / _ `/ / / -_) _  / / __/ / _ \/ _ \ ║
║                          /___/\__/_/ /_/\_,_/_/  \__/\_,_/_/\__/_/\___/_//_/ ║
║                                           for the Arduino Mega 2560 Rev3     ║
╚═════════════════════════════════════════════════╝
                  Controle de Diodes via une connection série par USB.
                       Ecris par "Giaccone R." Aka "Lunar-D".
                     Bassé sur la "Stack Overflow Documentation".
                                Disponible sur GitHub.
*/

//----------------------------------------------------*fonctions normales*----------------------------------------------------
//la fonction Setup s'exécute une seule fois lorsque vous appuyez sur reset ou lorsque vous mettez la carte sous tension.
void setup() {
  //mise en place des sortie (led+série)
  Serial.begin(9600); // Commence l'écoute sur le port 9600 pour le port série (9600 baud)
  while (!Serial) {
    ; // attend la connection usb série
  }
  welcomeMSG();
  //Initialiser toutes les broches numériques en tant que sortie.
  LedInit();
  delay(100); 
  //Metre toute les Diode sur Off (LOW)
  LedOff();
  Serial.print("\n -- PRET A COMUNIQUER.\n");
}
//----------------------------------------------------------------------------------------------------------------------------
//la fonction de boucle s'exécute encore et encore pour toujours
void loop() {

   if(Serial.available() > 0) // Read from serial port
    {
      int ReaderFromNode; // Store current character
      char ReaderFromNodeChar;
      ReaderFromNode = Serial.read();
      ReaderFromNodeChar = ReaderFromNode;
      if(ReaderFromNode != 10){
        Serial.print("\n vous avec envoyer: ");
        Serial.print(ReaderFromNode);
        Serial.print("(");
        Serial.print(ReaderFromNodeChar);
        Serial.print(")");
      }
      convertToState(ReaderFromNode); // Convert character to state  
    }
  delay(1000); 
}

//---------------------------------------------------*fonctions additionels*--------------------------------------------------
//conversion de carateres vers action
void convertToState(char chr) {
  //debug
  int led = chr;
  //partie ON
  if (led <= 54){
    digitalWrite(led, HIGH);
    }
  //partie OFF
  if (led >= 55){
    int ledoff = led - 54;
    digitalWrite(ledoff, LOW);
    }
  //partie OFF
}
//----------------------------------------------------------------------------------------------------------------------------
//met toute les led(pin) sur off
void LedOff(){
  Serial.print("\n -- ETAPE 2 : METRE LES LED SUR OFF...\n");
  int led = 0;
  for( led = 0; led < 54; led++ ) {
      digitalWrite(led, LOW);
      Serial.print("led:");
      Serial.print(led);
      Serial.print(" off\n");
  }
  Serial.print("\nETAPE 2: OK.");
}
//----------------------------------------------------------------------------------------------------------------------------
//met toute les pin sur OUTPUT  
void LedInit(){
  Serial.print("\n -- ETAPE 1 : DEFINIR LES LED...\n");
  int led = 0;
  for( led = 0; led < 54; led++ ) {
      pinMode(led, OUTPUT);
      Serial.print("PORT:");
      Serial.print(led);
      Serial.print(" Set sur OUTPUT\n");
  }
  Serial.print("ETAPE 1: OK.");
}

void welcomeMSG(){
      Serial.print("╔═════════════════════════════════════════════════╗\n"); 
      Serial.print("║    __    __________                             __  _______ ____             ║\n");
      Serial.print("║   / /   / ____/ __ \\   ____ _   _____  _____   / / / / ___// __ )            ║\n");
      Serial.print("║  / /   / __/ / / / /  / __ \\ | / / _ \\/ ___/  / / / /\\__ \\/ __  |            ║\n");
      Serial.print("║ / /___/ /___/ /_/ /  / /_/ / |/ /  __/ /     / /_/ /___/ / /_/ /             ║\n");
      Serial.print("║/_____/_____/_____/   \\____/|___/\\___/_/      \\____//____/_____/              ║\n");
      Serial.print("║                                         _      __         ___ __  _          ║\n");
      Serial.print("║                            ___ ___ ____(_)__ _/ / ___ ___/ (_) /_(_)__  ___  ║\n");
      Serial.print("║                           (_-</ -_) __/ / _ `/ / / -_) _  / / __/ / _ \\/ _ \\ ║\n");
      Serial.print("║                          /___/\\__/_/ /_/\\_,_/_/  \\__/\\_,_/_/\\__/_/\\___/_/\/_/ ║\n");
      Serial.print("║                                           for the Arduino Mega 2560 Rev3     ║\n");
      Serial.print("╚═════════════════════════════════════════════════╝\n");
      Serial.print("                 Controle de Diodes via une connection série par USB.\n");
      Serial.print("                       Ecris par 'Giaccone R.' Aka 'Lunar-D'.\n");
      Serial.print("                     Bassé sur la 'Stack Overflow Documentation'.\n");
      Serial.print("                                Disponible sur GitHub.\n");
      Serial.print("\n");
      Serial.print("\n");
      Serial.print("\n");
      Serial.print("Lancement des préparatifs ...\n");
      delay(500);
}
