#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>

//Set the window size
int width=800, height=600;

//First rule - three active cells
bool three_active (int tab[800][600], int x, int y)
{
    int itr=0;
    if (x==0 && y==0)
    {
        if (tab[x+1][y]==1) itr++;
        if (tab[x][y+1]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
    }
    if (x==800 && y==0)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
    }
    if (x==0 && y==600)
    {
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
    }
    if (x==800 && y==600)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x][y-1]==1) itr++;
    }
    if (x>0 && x<800 && y==0)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
    }
    if (x==0 && y>0 && y<600)
    {
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
    }
    if (x==800 && y>0 && y<600)
    {
        if (tab[x][y-1]==1) itr++;
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
    }
    if (x>0 && x<800 && y==600)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
    }
    else
    {
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x-1][y]==1) itr++;
    }
    if (itr==3) return true;
    else return false;
}

//Second rule - two active cells
bool two_active (int tab[800][600], int x, int y)
{
    int itr=0;
    if (x==0 && y==0)
    {
        if (tab[x+1][y]==1) itr++;
        if (tab[x][y+1]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
    }
    if (x==800 && y==0)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
    }
    if (x==0 && y==600)
    {
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
    }
    if (x==800 && y==600)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x][y-1]==1) itr++;
    }
    if (x>0 && x<800 && y==0)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
    }
    if (x==0 && y>0 && y<600)
    {
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
    }
    if (x==800 && y>0 && y<600)
    {
        if (tab[x][y-1]==1) itr++;
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
    }
    if (x>0 && x<800 && y==600)
    {
        if (tab[x-1][y]==1) itr++;
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
    }
    else
    {
        if (tab[x-1][y-1]==1) itr++;
        if (tab[x][y-1]==1) itr++;
        if (tab[x+1][y-1]==1) itr++;
        if (tab[x+1][y]==1) itr++;
        if (tab[x+1][y+1]==1) itr++;
        if (tab[x][y+1]==1) itr++;
        if (tab[x-1][y+1]==1) itr++;
        if (tab[x-1][y]==1) itr++;
    }
    if (itr==2) return true;
    else return false;
}

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(width, height, 32), "Game of Life");
    int tab1[800][600], tab2[800][600], random_x, random_y;

    for (int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            tab1[i][j]=0;
            tab2[i][j]=0;
        }
    }

	//Starting point for pseudorandom number generator
    srand(time(NULL));
    sf::RectangleShape rectangle(sf::Vector2f(1,1));

    //Random generator start
    for (int i=0; i<48000; i++)
    {
            random_x = ((rand() % width) + 0);
            random_y = ((rand() % height) + 0);
            tab1[random_x][random_y] = 1;
            tab2[random_x][random_y] = tab1[random_x][random_y];
    }

    //Islands start
    /*for (int i=0; i<300000; i++)
    {
            random_x = ((rand() % 400) + 250);
            random_y = ((rand() % 300) + 150);
            tab1[random_x][random_y] = 1;
            tab2[random_x][random_y] = tab1[random_x][random_y];
    }*/
    /*
    for (int i=0;i<width;i++)
    {
        for (int j=0;j<height;j++)
        {
            rectangle.setPosition(i,j);
            if(tab1[i][j]==1)
            {
                rectangle.setFillColor(sf::Color::Green);
                app.draw(rectangle);

            }
        }
    }*/


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
        for (int i=0;i<width;i++)
        {
            for (int j=0;j<height;j++)
            {
                if (tab1[i][j]==0 && three_active(tab1,i,j)) tab2[i][j] = 1;
                else if (tab1[i][j]==1 && (two_active(tab1,i,j) || three_active(tab1,i,j))) tab2[i][j] = 1;
                else tab2[i][j] = 0;
                tab1[i][j] = tab2[i][j];

                rectangle.setPosition(i,j);
                if(tab2[i][j]==1)
                {
                    rectangle.setFillColor(sf::Color::Green);
                    app.draw(rectangle);
                }else if (tab2[i][j]==0)
                {
                    rectangle.setFillColor(sf::Color::Black);
                    app.draw(rectangle);
                }
            }
        }
        /*
        for (int i=0;i<width;i++)
        {
            for (int j=0;j<height;j++)
            {
                rectangle.setPosition(i,j);
                if(tab2[i][j]==1)
                {
                    rectangle.setFillColor(sf::Color::Green);
                    app.draw(rectangle);
                }else if (tab2[i][j]==0)
                {
                    rectangle.setFillColor(sf::Color::Black);
                    app.draw(rectangle);
                }
            }
        }*/
		
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
