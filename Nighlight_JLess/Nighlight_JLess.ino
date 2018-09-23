//Автоматический ночник
const int RLED=9; //Контакт 9 для красного цвета RGB
const int LIGHT=0; //А0 для входа фоторезистора.
const int MIN_LIGHT=200; //Нижний порог освещенности
const int MAX_LIGHT=900; //Верхний порог освещенности
int val = 0; //Переменная для приема аналогового значения

void setup() {
   pinMode(RLED,OUTPUT);
   Serial.begin(9600);  
}

void loop() {
  val = analogRead(LIGHT); //Чтение показаий фоторезистора
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); //Вызов функции map для приведения соответствия значений
  val = constrain(val, 0, 255);     // Обозначение границ
  Serial.println(val);
  analogWrite(RLED,val);            // Управление светодиодом

}
