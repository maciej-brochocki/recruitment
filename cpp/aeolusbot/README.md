# Sample code 
Example of using openCV to load and view images

## Requirements
- OpenCV 2.X
- CMake > 2.8

## Building
    cmake .
    make

## Usage
    gfx_api <Image_Path> [COMMAND]

    supported COMMANDs:
      R x y t        - FIND_REGION starting at (x,y) use t threshold for similarity
                       pixels will be included in the region if they differ at most t at each RGB from (x,y)
      P              - FIND_PERIMETER
      I              - DISPLAY_IMAGE
      X              - DISPLAY_PIXELS
      S <Image_Path> - SAVE_PIXELS
      T              - TEXT_OUTPUT of PIXELS set
                       redirect console output to a file if needed
      O s            - FIND_SMOOTH_PERIMETER by dividing perimeter into s equal segments
                       and using Centripetal Catmull–Rom splines. s must be greater or equal 4.

    can try ./test as a full example

    This allows a creation of a very flexible pipelines - operations can be repeated, sent to other functions, etc.

## Smoothing
CatmullRom was chosen for smoothing for its simplicity as I don't know the actual application.
Curve goes through its control points so it has a very simple lower degree representation.
Number of segments is a parameter, too few points and the shape won't be preserved,
too many points and the junk will influence the shape too much, always a compromise.
I've considered other proposed approaches (bezier curves, splines, curve fitting, interpolation, gaussian smoothing),
but they would produce the similar results.

## Potential improvements
To get rid off a small junk I would use erode and dilate before smoothing, but since I'm not allowed to use openCV
I'm not going to implement them and reinvent the wheel once again ;).

To get rid off an arrow I would use dilate and erode before smoothing.
Convex hull instead of an actual perimeter could be also used for that, but that would capture too much.

Smoothing can be improved by a more intelligent segmentation - not even, but for example upon a certain angle change.

## References
    https://en.wikipedia.org/wiki/Centripetal_Catmull%E2%80%93Rom_spline
