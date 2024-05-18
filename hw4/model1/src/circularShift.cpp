#include <circularShift.h>
#include <vector>
#include <globals.h>
void circularShift()
{
    std::vector<int> word_indices;
    std::vector<int> line_indices;

    for (int i = 0; i < line_index_.size(); ++i)
    {
        word_indices.push_back(line_index_[i]);
        line_indices.push_back(i);

        int last_index = 0;

        if (i != (line_index_.size() - 1))
        {
            last_index = line_index_[i + 1];
        }
        else
        {
            last_index = chars_.size();
        }

        for (int j = line_index_[i]; j < last_index; ++j)
        {
            if (chars_[j] == ' ')
            {
                word_indices.push_back(j + 1);
                line_indices.push_back(i);
            }
        }
    }
    circular_shifts_ = {
        std::vector<int>(word_indices.size(), 0), 
        std::vector<int>(word_indices.size(), 0)
    };
    for (int i = 0; i < word_indices.size(); ++i)
    {
        circular_shifts_[0][i] = line_indices[i];
        circular_shifts_[1][i] = word_indices[i];
    }
}


