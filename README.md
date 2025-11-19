🌀 Fractal Generator in C
Mandelbrot • Burning Ship • Tricorn

A modular C project implementing three famous fractal sets using the escape-time algorithm, with clean file separation, reusable rendering logic, and text-based output.

📌 Project Overview

This project generates three mathematically significant fractals:

Mandelbrot Set

Burning Ship Set

Tricorn (Mandelbar) Set

Each fractal is computed using the escape-time iterative method, mapped over a 2D grid, and saved as a text-formatted output (0 = inside, 1 = outside).
The project is written in standard C and organized in a modular structure with separate .c and .h files for each fractal.

🗂️ Project Structure
Fractals-Project/
│
├── main.c
│
├── mandelbrot.c
├── mandelbrot.h
│
├── burningship.c
├── burningship.h
│
├── tricorn.c
├── tricorn.h
│
└── README.md

⚙️ How It Works

All fractals use the same escape-time logic:

Map each pixel → complex number c

Initialize z = 0

Iterate using the fractal’s transformation rule

If |z| > 2, the point escapes → mark as 1

If the max iteration is reached, point stays bounded → mark as 0

Save result row-by-row into a text file

Each fractal uses its own formula:

1. Mandelbrot
                zn+1=zn2+c
2. Burning Ship
                zn+1=(∣Re(zn)∣+i∣Im(zn)∣)2+c
3. Tricorn
                zn+1=(zn2)‾+c


🖥️ Compiling & Running

Compile using GCC:
gcc main.c mandelbrot.c burningship.c tricorn.c -o fractals -lm
Run the program:
./fractals

Choose a fractal from the menu:
1. Mandelbrot
2. Burning Ship
3. Tricorn
   
The program outputs:

mandelbrot.txt
burningship.txt
tricorn.txt

🧩 Output Format

The output files store fractals in a simple binary-text style:

0 → inside the set

1 → escaped / outside the set

Example (shortened):

00011111...
00011111...
11100000...
This makes the output easy to analyze, visualize, or convert for further processing.

🔧 Customization Options

You can modify the following parameters in main.c:

WIDTH, HEIGHT → resolution

MAX_ITER → detail level

(x_min, x_max, y_min, y_max) → view window

Try increasing MAX_ITER for sharper, more detailed fractal edges.

🚀 Future Enhancements

Some ideas for expansion:

Export fractals as PPM/PNG images

Enable interactive zooming

Add Julia sets

Add color gradients instead of binary output

Implement a simple GUI

📜 License

This project is open-source under the MIT License.
Feel free to modify, share, and build upon it.

