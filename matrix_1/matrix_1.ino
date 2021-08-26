#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 9;
int numberOfHorizontalDisplays = 4; // количество матриц по-горизонтали
int numberOfVerticalDisplays = 1; // количество матриц по-вертикали
int b[8]={0, 1, 2, 3, 4, 5, 6, 7};
int a[8]={0, 1, 2 ,3, 4, 5, 6, 7};

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

void setup() {
    matrix.setIntensity(15); // яркость от 0 до 15
    
}

void loop() {
    matrix.drawPixel(random (a), random (b), HIGH); // зажигаем пиксель с координатами {3,4}
    matrix.write(); // вывод всех пикселей на матрицу
    
    matrix.drawPixel (random(a), random (b), LOW); // гасим пиксель
    matrix.write();
   
}
