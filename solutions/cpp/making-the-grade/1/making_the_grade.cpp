#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> result={} ;
    for (int i = 0; i<student_scores.size(); i++)
        {
            result.emplace_back(static_cast<int>(student_scores[i]));
        }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int count=0;
    for (int i = 0;i<student_scores.size();i++)
        {
            if (student_scores[i]<=40)
            {
                count+=1;
            }
        }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    std::array<int,4> array_result;
    int range = (highest_score-40)/4;
    array_result[0]=41;
    array_result[1]=41+range;
    array_result[2]=41+2*range;
    array_result[3]=41+3*range;

    return array_result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> result;
    for (int i = 0;i<student_scores.size();i++)
        {
          result.emplace_back(std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));  
        }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (int i = 0; i<student_scores.size();i++)
        {
            if (student_scores[i]==100)
            {
                return student_names[i];
            }
        }
    return "";
}
