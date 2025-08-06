# FDF - Wireframe 3D Renderer

## About

**FDF (Fil de Fer)** is a computer graphics project at École 42 that introduces 3D programming and rendering concepts. The project involves creating a wireframe renderer that displays heightmaps as 3D landscapes using isometric projection. FDF teaches fundamental graphics programming, matrix transformations, and real-time rendering while working with the MLX graphics library.

The project transforms 2D elevation data into interactive 3D visualizations, providing hands-on experience with coordinate systems, projection mathematics, and graphics programming fundamentals that serve as the foundation for more advanced computer graphics work.

## Learning Objectives

- **3D Mathematics**: Understanding coordinate systems, transformations, and projections
- **Graphics Programming**: Working with graphics libraries and rendering pipelines
- **Matrix Operations**: Implementing rotation, translation, and scaling transformations
- **Event Handling**: Managing user input and real-time interaction
- **Memory Management**: Handling large datasets and dynamic graphics memory
- **Algorithm Optimization**: Creating efficient rendering and drawing algorithms
- **File Processing**: Parsing and validating complex data formats

## Core Features

### 3D Visualization
- **Isometric Projection**: Default 3D view with proper depth perception
- **Wireframe Rendering**: Clean line-based 3D mesh visualization
- **Height Mapping**: Elevation data converted to 3D coordinates
- **Color Gradients**: Height-based color mapping for visual depth

### Interactive Controls
- **Real-time Transformations**: Live scaling, and translation
- **Zoom Functionality**: Dynamic scaling for detailed examination

### Map Processing
- **File Format Support**: Custom heightmap file parsing
- **Dynamic Sizing**: Handling maps of various dimensions
- **Data Validation**: Robust error checking for invalid map data
- **Memory Optimization**: Efficient handling of large datasets

## Technical Implementation

### Coordinate System Architecture

#### Map Data Structure
```c
typedef struct s_map
{
    int width;
    int height;
    int **z_matrix;
    int **color_matrix;
    int z_range;
    int color_range;
}   t_map;
```

### Projection Mathematics

#### Isometric Projection Formula
The default isometric projection transforms 3D coordinates (x, y, z) to 2D screen coordinates:
```c
int iso_x = (x - y) * cos(0.523599); // cos(30°)
int iso_y = (x + y) * sin(0.523599) - z; // sin(30°)
```

### Rendering Pipeline

#### Line Drawing Algorithm
Implementation of Bresenham's line algorithm for efficient wireframe rendering:
1. Calculate line parameters and step values
2. Determine pixel positions along the line
3. Apply color interpolation for gradient effects
4. Handle steep slopes and edge cases

### Graphics Library Integration

#### MLX Library Usage
- **Window Management**: Creating and managing graphics windows
- **Pixel Manipulation**: Direct pixel buffer access for drawing operations
- **Event Handling**: Keyboard and mouse input processing
- **Image Management**: Buffer swapping and display updates

#### Performance Optimizations
- **Efficient Drawing**: Optimized line drawing algorithms
- **Memory Management**: Smart buffer allocation and deallocation
- **Update Strategies**: Selective redrawing for interactive performance
- **Resource Cleanup**: Proper cleanup of graphics resources

## Map File Format

### Standard Format
```
10 0 0 0 0 0 0 10
0  1 2 3 4 5 6  0
0  2 4 6 8 10 12 0
0  1 2 3 4 5 6  0
10 0 0 0 0 0 0 10
```

### File Processing
- **Parsing Algorithm**: Robust parsing with error detection
- **Memory Allocation**: Dynamic allocation based on map dimensions
- **Validation**: Comprehensive input validation and error reporting
- **Color Processing**: Hex color code parsing and conversion

## Usage Examples

### Basic Map Rendering
```bash
# Render a simple heightmap
./fdf maps/42.fdf

# Load and display various test maps
./fdf maps/pyramid.fdf
./fdf maps/julia.fdf
./fdf maps/mars.fdf
```

### Interactive Controls
```
ESC         - Exit program
+/-         - Zoom in/out
Arrow Keys  - Translate view
R           - Reset to default view
```

## Advanced Implementation Features

### Multiple Projections
- **Isometric View**: Standard 3D representation with equal axis scaling
- **Parallel Projection**: Orthographic view without perspective distortion
- **Perspective Projection**: Realistic depth with vanishing points
- **Custom Views**: User-defined projection parameters

### Performance Optimizations
- **Culling Algorithms**: Removing non-visible elements for better performance
- **Level of Detail**: Adaptive rendering based on zoom level
- **Efficient Memory Usage**: Optimized data structures for large maps
- **Multi-threading**: Parallel processing for complex transformations

## Compilation and Testing

### Standard Build
```bash
# Compile with MLX library
make
# or manually:
gcc -Wall -Wextra -Werror *.c -lmlx -lXext -lX11 -lm -o fdf
```

### macOS Build
```bash
# macOS specific compilation
gcc -Wall -Wextra -Werror *.c -lmlx -framework OpenGL -framework AppKit -o fdf
```

## Technical Challenges

### 3D Mathematics Complexity
Understanding and implementing coordinate transformations, projection mathematics, and matrix operations for realistic 3D rendering.

### Real-time Performance
Maintaining smooth interactive performance while rendering complex wireframe models with thousands of lines and vertices.

### Memory Management
Efficiently handling large heightmap datasets while preventing memory leaks in graphics-intensive applications.

### Cross-platform Compatibility
Managing differences between graphics libraries and window systems across different operating systems.

## Key Challenges & Solutions

### Projection Accuracy
- **Challenge**: Implementing mathematically correct 3D to 2D projections
- **Solution**: Proper matrix mathematics and transformation pipeline implementation

### Interactive Performance
- **Challenge**: Maintaining real-time performance during user interactions
- **Solution**: Optimized rendering algorithms and selective screen updates

### Large Dataset Handling
- **Challenge**: Processing and rendering large heightmaps efficiently
- **Solution**: Memory optimization techniques and adaptive level-of-detail rendering

## Skills Demonstrated

- **Computer Graphics**: Fundamental 3D rendering and projection techniques
- **Mathematical Programming**: Implementation of complex mathematical transformations
- **Graphics Library Usage**: Proficiency with low-level graphics programming
- **Interactive Programming**: Real-time event handling and user interface development
- **Performance Optimization**: Creating efficient algorithms for graphics applications
- **File Processing**: Robust parsing and validation of complex data formats
- **Memory Management**: Efficient handling of large datasets in graphics contexts

## Applications and Extensions

The concepts learned in FDF form the foundation for advanced graphics programming:
- **Game Development**: 3D game engines and real-time rendering
- **Data Visualization**: Scientific and engineering data representation
- **CAD Applications**: Computer-aided design and modeling software
- **Simulation Software**: 3D visualization of scientific simulations
- **Virtual Reality**: VR application development and 3D environments

## Related Projects

This project serves as preparation for more advanced graphics projects:
- **cub3d**: 3D raycasting game engine
- **miniRT**: Ray tracing renderer with advanced lighting
- **scop**: 3D model loading and OpenGL rendering
- Advanced shader programming and modern graphics APIs

## Notes

The FDF project represents a crucial introduction to computer graphics programming, providing essential experience with 3D mathematics, rendering algorithms, and interactive graphics development. It demonstrates the ability to translate mathematical concepts into functional graphics applications.

The project emphasizes practical implementation of theoretical concepts, requiring deep understanding of coordinate systems, transformations, and rendering pipelines. The interactive nature of the application showcases real-time programming skills essential for graphics and game development.

This foundation project demonstrates readiness for advanced graphics programming challenges and provides the mathematical and programming foundation necessary for modern computer graphics development.

---

*Developed as part of the École 42 curriculum - entering the world of computer graphics through 3D wireframe visualization.*
