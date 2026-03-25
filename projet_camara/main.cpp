#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Camera
{
private:
    int cameraId;
    string cameraName;
    bool status;

public:
    Camera(int id, string name)
    {
        cameraId = id;
        cameraName = name;
        status = false; // initially OFF
    }

    void turnOn()
    {
        status = true;
        cout << cameraName << " is now ON." << endl;
    }

    void turnOff()
    {
        status = false;
        cout << cameraName << " is now OFF." << endl;
    }

    void display() const
    {
        cout << "Camera ID: " << cameraId << endl;
        cout << "Camera Name: " << cameraName << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
        cout << "--------------------------" << endl;
    }

    int getId() const
    {
        return cameraId;
    }
};

int main()
{
    vector<Camera> cameras;
    int choice;

    do
    {
        cout << "\n===== Camera System Menu =====" << endl;
        cout << "1. Add Camera" << endl;
        cout << "2. Turn ON Camera" << endl;
        cout << "3. Turn OFF Camera" << endl;
        cout << "4. Display All Cameras" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            cout << "Enter Camera ID: ";
            cin >> id;
            cout << "Enter Camera Name: ";
            cin >> name;

            cameras.push_back(Camera(id, name));
            cout << "Camera added successfully." << endl;
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Camera ID to turn ON: ";
            cin >> id;

            bool found = false;
            for (auto &cam : cameras)
            {
                if (cam.getId() == id)
                {
                    cam.turnOn();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Camera not found." << endl;
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Camera ID to turn OFF: ";
            cin >> id;

            bool found = false;
            for (auto &cam : cameras)
            {
                if (cam.getId() == id)
                {
                    cam.turnOff();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Camera not found." << endl;
        }
        else if (choice == 4)
        {
            if (cameras.empty())
            {
                cout << "No cameras available." << endl;
            }
            else
            {
                for (const auto &cam : cameras)
                {
                    cam.display();
                }
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting program..." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    return 0;
}