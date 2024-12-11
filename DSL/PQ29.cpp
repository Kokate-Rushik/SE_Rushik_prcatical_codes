#include <iostream>
#include <queue>
#include <string>
using namespace std;

class JobQueue {
private:
    queue<string> jobs;

public:
    // Function to add a job to the queue
    void addJob(const string& job) {
        jobs.push(job);
        cout << "Job '" << job << "' added to the queue." << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobs.empty()) {
            cout << "No jobs in the queue to delete." << endl;
        } else {
            cout << "Job '" << jobs.front() << "' completed and removed from the queue." << endl;
            jobs.pop();
        }
    }

    // Function to display all jobs in the queue
    void displayJobs() const {
        if (jobs.empty()) {
            cout << "No jobs in the queue." << endl;
        } else {
            queue<string> temp = jobs; // Copy to preserve original queue
            cout << "Jobs in the queue: ";
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    JobQueue jq;
    int choice;
    string jobName;

    do {
        cout << "\nJob Queue Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job name to add: ";
                cin >> jobName;
                jq.addJob(jobName);
                break;
            case 2:
                jq.deleteJob();
                break;
            case 3:
                jq.displayJobs();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
