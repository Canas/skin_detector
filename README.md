Skin Detection using Mixture of Gaussians
=========================================
This code implements the Jones & Rehg algorithm in C++ using OpenCV 2.4.9. The code was originally developed as a homework for a Computer Vision course so it possesses no optimizations whatsoever and focused solely on working as intended.

Notes
-----
- The code is intended to for use with the data available here (www.cec.uchile.cl/~crsilva/projects/skindetector/data.rar).
- The tools folder contains some Matlab functions that can process the output of the program to plot a ROC curve and analize the effectiveness of the code.

Instructions
------------
After compiling, the program has two ways of executing:
```bash
skin_detector demo
```
```bash
skin_detector (image_path) (threshold)
```

The first one calculates the ROC curve for all the images in the data folder, evaluating its ground truth vs the detector itself. The output of this execution can be seen in the output folder.

The second one only processes the input image with the given threshold,. The ouput image with the skin detection can be seen on the same folder as the executable.


References
----------
Jones, M.J.; Rehg, J.M., "Statistical color models with application to skin detection," Computer Vision and pattern Recognition, 1999. IEEE Computer Society Conference on. , vol.1, no., pp.,280 Vol. 1, 1999

Credits and licensing
---------------------
Author: Cristobal Silva, crsilva at ing dot uchile dot cl