# Polynomial Root Finder

## What it does:
This algorithm find every root for polynomial in a given range in the complex plane. The user specifies the size of the search area and density of the search grid.
The inspiration for this project came from [Newton's Fractal](https://www.youtube.com/watch?v=-RdOwhmqP5s&ab_channel=3Blue1Brown "Project Inspiration")

## What I learned:
Complex Newtons Method - Newtons method is used iteratively in the complex plane to converge the search grid to the nearest root 

Clustering and Convergence - I learned how to effectively define my own clusters without the number of clusters being predefined because the polynomial may have repeated roots. Convergence was a helpful way to test when to invoke clustering as the points settle to their equilibria. 

## Next Steps:
The only things left to do are:
1. Dividing out the roots found using polynomial division and rerunning the algorithm recursively if needed.
