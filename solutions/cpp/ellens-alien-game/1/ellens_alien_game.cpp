namespace targets {
// TODO: Insert the code for the alien class here
class Alien 
    {
    public : 
     Alien(int x, int y)
    {
        x_coordinate = x;
        y_coordinate = y;
        health = 3;
    }
    int get_health()
    {
        return health;
    }
    bool hit()
    {
        if (health >0)
        {
            --health;
            return true;
        }
        return false;
    }

    bool is_alive()
    {
        if (health<=0)
        {
            return false;
        }
        return true;
    }

    
    bool teleport(int x_new, int y_new)
    {
        x_coordinate=x_new;
        y_coordinate=y_new;
        return true;
    }
    
    bool collision_detection(Alien otherAlien)
    {
        if (otherAlien.x_coordinate == x_coordinate && otherAlien.y_coordinate == y_coordinate)
        {
            return true;
        }
        return false;
    }
    public :
    int x_coordinate;
    int y_coordinate;
    int health;
    };
}  // namespace targets
