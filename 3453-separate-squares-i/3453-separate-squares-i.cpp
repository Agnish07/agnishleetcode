class Solution {
public:
    double minY(vector<vector<int>>& squares){
        double miny = squares[0][1];
        for(const auto& square : squares){
            miny = min(square[1]*1.0, miny);
        }
        return miny;
    }
    double maxY(vector<vector<int>>& squares){
        double maxy = squares[0][1] + squares[0][2];
        for(const auto& square : squares){
            maxy = max((square[1]+square[2])*1.0, maxy);
        }
        return maxy;
    }

    bool lowerlarger(vector<vector<int>>& squares,double midy){
        double lowerarea = 0, upperarea = 0;

        for(const auto& square : squares){
            double topy = square[1]+square[2];
            double bottomy = square[1];
            double side = square[2];

            if(midy >= topy){
                lowerarea += side*side;
            }
            else if(midy <= bottomy){
                upperarea += side*side;
            }
            else{
                upperarea += ((topy-midy)*side);
                lowerarea += ((midy-bottomy)*side);
            }
        }

        return lowerarea >= upperarea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double miny = minY(squares);
        double maxy = maxY(squares);
        double pr = 1e-5;

        while(maxy - miny > pr){
            double midy = (miny + maxy)/2;
            if(lowerlarger(squares, midy)){
                maxy = midy;
            }
            else{
                miny = midy;
            }
        }
        return maxy;
    }   
};