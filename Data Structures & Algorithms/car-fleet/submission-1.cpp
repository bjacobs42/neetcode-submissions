class Solution
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        std::vector<std::pair<int, int>> cars;
        std::stack<std::pair<int, int>> fleet;

        cars.reserve(position.size());
        for (int i = 0; i < position.size(); ++i)
            cars.emplace_back(position[i], speed[i]);

        std::sort(cars.rbegin(), cars.rend());

        int i = 0;
        int fleetCount = 0;
        while (i < position.size())
        {
            int j = i + 1;
            double max_time = (double)(target - cars[i].first) / cars[i].second;

            while (j < position.size())
            {
                double time = (double)(target - cars[j].first) / cars[j].second;
                std::cout << time << ", " << max_time << std::endl;
                if (time > max_time)
                    break;
                ++j;
            }
            i = j;
            ++fleetCount;
        }
        return (fleetCount);
    }
};
