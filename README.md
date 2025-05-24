# 42 Cursus

## FDF 🗺
This is the first graphic project in the 42 School using the minimalistic codam library: [MLX42](https://github.com/codam-coding-college/MLX42)  
In this project you will transform a map consisting of numbers (representing the Z axis) and colors (in hexadecimal format) into a 3D wireframe graphic.  

![alt text](https://user-images.githubusercontent.com/21006147/190404961-988cedf9-bed6-417f-bed3-eb5dc2b7afda.png)

It reinforces various programming concepts such as file handling, graphics rendering, and user input processing. You will learn how to use an external library by reading its documentation and testing its features, as well as fundamental mathematical concepts like linear algebra, trigonometry, and the **Bresenham line drawing algorithm**.  

<p float="left">
  <img src="https://miro.medium.com/v2/resize:fit:1400/1*l552tTR3_ywont4BRuU3lQ.png" width="300" />
  <img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/0*dt0w0ps7mLeqPG9U.gif" width="300" />
</p>

## Map format
```c
0  0  0  0  0  0  0  0  0  0
0 10 10 10 10 10 10 10 10  0
0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0
0 10 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 15,0xFF0000 10  0
0  5 15,0xFF0000 10 12 15,0xFF0000 15,0xFF0000 13 10  0
0  5 10  5  7 12 12 12 10  0
0  5  7  1  2  7  5  5  7  0
0  3  0  0  1  2  2  2  5  0
0  1  0  0  0  0  0  0  3  0
0  0  0  0  0  0  0  0  0  0
```

Use a coma after the Z axis coordenate to specify the color.  

## Controls
Use the arrows to move.  
Use 1 and 0 to increse/decrease the height. 

![alt text](https://miro.medium.com/v2/resize:fit:916/format:webp/1*1erLSI8XPlNmkhvz0LvFqQ.gif)

## How to use:
1. Clone the repository:
```c
git clone https://github.com/aldferna/FDF.git
```
2. Compile it:
```c
make
```
3. Execute with a valid map:
```c
./fdf test_maps/42.fdf
```

