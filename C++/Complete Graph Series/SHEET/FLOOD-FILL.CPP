#include<bits/stdc++.h>
using namespace std;





// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.






//paint adjacent with same color to new color
void paint(int x , int y ,vector<vector<int>>& image,
int oldcolor , int newColor ,vector<vector<int>>&visited,int n ,int m)

{
    
    if(x>=n || x<0 ||y>=m ||y<0){return;} //out of bounds 
    
    if(visited[x][y] || image[x][y]!=oldcolor){return;}
    
    visited[x][y]= 1;
    image[x][y] = newColor;
    
    //bfs in adjacent
     paint(x+1,y,image,oldcolor,newColor , visited ,n,m);
     paint(x-1,y,image,oldcolor,newColor , visited ,n,m);
     paint(x,y+1,image,oldcolor,newColor , visited ,n,m);
     paint(x,y-1,image,oldcolor,newColor , visited ,n,m);
}


    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc];
        
       vector<vector<int>> visited( n , vector<int> (m, 0));
        
        paint(sr,sc,image,oldcolor,newColor , visited ,n,m);
        return image;
        
    }