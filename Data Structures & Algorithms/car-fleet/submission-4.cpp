class Solution
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        std::vector<std::pair<int, int>> cars;

        cars.reserve(position.size());
        for (int i = 0; i < position.size(); ++i)
            cars.emplace_back(position[i], speed[i]);

        std::sort(cars.rbegin(), cars.rend());

        double fleetArrival = 0;
        int fleetCount = 0;
        for (auto &[pos, spd] : cars)
        {
            double carArrival = (double)(target - pos) / spd;

            if (carArrival > fleetArrival)
            {
                fleetArrival = carArrival;
                ++fleetCount;
            }
        }
        return (fleetCount);
    }
};
