









const int MAP_SIZE = 10;
enum palette {red, blue, green, yellow, none};

//
//
class color {
public:
    color ()          : tint(none) {};
    color (palette c) : tint(c)    {};
    color& operator++() {tint = palette(tint + 1); return *this; };
    friend std::ostream& operator<<(std::ostream&, color);
    
private:
    palette tint;
};

//
//
class map{
public:
           map ();
    bool   isValidColoring         (int, color) const;
    void   colorCountry            (int country, color c) { coloring[country] = c; };
    int    numberOfCountries       () const               { return numOfCountries; };
    friend std::ostream& operator<<(std::ostream&, const map&);
    friend std::istream& operator>>(std::istream&, map& );
private:
    int numOfCountries;
    bool neighbor[MAP_SIZE][MAP_SIZE];
    color coloring[MAP_SIZE];
};
