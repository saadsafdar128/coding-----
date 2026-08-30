#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice = 0;
    int choicepatientmanagement = 0;

    int Id[100] = {};
    string Name[100] = {};
    int Age[100] = {};
    string Gender[100]{};
    string Disease[100] = {};
    string Phone[100] = {};
    int n = 0;
    int docId[100] = {};
    string docName[100] = {};
    string docSpec[100] = {};
    string docPhone[100] = {};
    string docGender[100] = {};
    int docAge[100] = {};
    int doctorCount = 0;
    const int MAX_APPOINTMENTS = 100;
    int patientcount = 0;
    int appointmentId[MAX_APPOINTMENTS];
    int appointmentPatientId[MAX_APPOINTMENTS];
    int appointmentDoctorId[MAX_APPOINTMENTS];
    string appointmentDate[MAX_APPOINTMENTS];
    string appointmentTime[MAX_APPOINTMENTS];

    int appointmentCount = 0;
    char continuationchoice3 = 'a';
    int billId[100], billPatientId[100], billCount = 0;
    string billPatientName[100], billDate[100];
    double billSubtotal[100], billTax[100], billDiscount[100], billTotal[100];

    char continuationchoice1;
    char continuationchoice2 = 'a';

    do {
        cout << "\t\t********************************************\n";
        cout << "\t\t* HOSPITAL       MANAGEMENT         SYSTEM *\n";
        cout << "\t\t********************************************\n";
        cout << "\t\t*        1-Patient Management              *\n";
        cout << "\t\t*        2-Doctor Managment                *\n";
        cout << "\t\t*        3-Appointment system              *\n";
        cout << "\t\t*        4-Billing system                  *\n";
        cout << "\t\t*        5-Reports                         *\n";
        cout << "\t\t*        6-Exit                            *\n";
        cout << "\t\t********************************************\n";
        cout << "                          ENTER YOUR CHOICE:";
        cin >> choice;

        // PATIENT MANAGEMENT MDULE BY MUHAMMAD SOHAIB
        if (choice == 1)
        {
            do {
                cout << "\t********************************************\n";
                cout << "\t*         PATIENT MANAGEMENT               *\n";
                cout << "\t********************************************\n";
                cout << "\t*        1-Add patient                     *\n";
                cout << "\t*        2-Remove patient                  *\n";
                cout << "\t*        3-Search patient                  *\n";
                cout << "\t*        4-Update patient                  *\n";
                cout << "\t*        5-Exit                            *\n";
                cout << "\t********************************************\n";
                cout << "                          ENTER YOUR CHOICE:";
                cin >> choicepatientmanagement;

                // ADD PATIENT
                if (choicepatientmanagement == 1)
                {
                    do
                    {
                        if (patientcount >= 100)
                        {
                            cout << "Storage full. Maximum 100 patients allowed.\n";
                            break;
                        }

                        cout << "Enter Patient ID: ";
                        cin >> Id[patientcount];
                        cin.ignore();

                        cout << "Enter Gender : ";
                        getline(cin, Gender[patientcount]);

                        cout << "Enter Patient Name: ";
                        getline(cin, Name[patientcount]);

                        cout << "Enter Patient Age: ";
                        cin >> Age[patientcount];
                        cin.ignore();

                        cout << "Enter Disease: ";
                        getline(cin, Disease[patientcount]);

                        cout << "Enter Phone Number: ";
                        getline(cin, Phone[patientcount]);

                        cout << "Patient added successfully\n\n";

                        patientcount++;

                        cout << "Add another patient? (y/n): ";
                        cin >> continuationchoice1;

                    } while (continuationchoice1 == 'y' || continuationchoice1 == 'Y');
                }

                // REMOVE PATIENT
                else if (choicepatientmanagement == 2)
                {
                    do
                    {
                        int patientIDremove;
                        bool found = false;
                        int index = -1;

                        cout << "Enter Patient ID to remove: ";
                        cin >> patientIDremove;

                        // search patient
                        for (int i = 0; i < patientcount; i++)
                        {
                            if (Id[i] == patientIDremove)
                            {
                                found = true;
                                index = i;
                                break;
                            }
                        }

                        if (!found)
                        {
                            cout << "Patient ID not found.\n";
                        }
                        else
                        {
                            // SHIFT LEFT from deleted index
                            for (int i = index; i < patientcount - 1; i++)
                            {
                                Id[i] = Id[i + 1];
                                Name[i] = Name[i + 1];
                                Age[i] = Age[i + 1];
                                Gender[i] = Gender[i + 1];
                                Disease[i] = Disease[i + 1];
                                Phone[i] = Phone[i + 1];
                            }

                            patientcount--;

                            cout << "Patient record removed successfully.\n";
                        }

                        cout << "Remove another patient? (y/n): ";
                        cin >> continuationchoice2;

                    } while (continuationchoice2 == 'y' || continuationchoice2 == 'Y');
                }
                // SEARCH PATIENT
                else if (choicepatientmanagement == 3)
                {
                    do
                    {
                        bool foundId = false;
                        int patientIdsearch = 0;

                        cout << "Enter the patient id: ";
                        cin >> patientIdsearch;

                        for (int i = 0; i < patientcount; i++)
                        {
                            if (Id[i] == patientIdsearch)
                            {
                                cout << "*****************************\n";
                                cout << " Patient id: " << Id[i] << endl;
                                cout << " Patient Name: " << Name[i] << endl;
                                cout << " Patient Age: " << Age[i] << endl;
                                cout << " Patient Disease: " << Disease[i] << endl;
                                cout << " Patient Gender: " << Gender[i] << endl;
                                cout << " Patient Phone: " << Phone[i] << endl;
                                cout << "*****************************\n";
                                foundId = true;
                                break;
                            }
                        }

                        if (!foundId)
                        {
                            cout << "Patient not found\n";
                        }

                        cout << "Do you want to search for another patient (y/n): ";
                        cin >> continuationchoice3;

                    } while (continuationchoice3 == 'y' || continuationchoice3 == 'Y');
                }

                // UPDATE PATIENT
                else if (choicepatientmanagement == 4)
                {
                    do
                    {
                        bool foundId = 0;
                        int t = 0;
                        int patientIdsearch = 0;

                        cout << "Enter the patient id: ";
                        cin >> patientIdsearch;

                        for (t = 0; t < patientcount; t++)
                        {
                            if (Id[t] == patientIdsearch)
                            {
                                foundId = 1;
                                break;
                            }
                        }

                        if (foundId)
                        {
                            cout << "What do you want to update:\n";
                            cout << "*****************************\n";
                            cout << " 1-Patient Id\n";
                            cout << " 2-Patient Name\n";
                            cout << " 3-Patient Gender\n";
                            cout << " 4-Patient Age\n";
                            cout << " 5-Patient Disease\n";
                            cout << " 6-Patient Phone\n";
                            cout << " 7-Whole Patients Information\n";
                            cout << "*****************************\n";

                            int choicepatientupdate = 0;
                            cout << "Enter your choice: ";
                            cin >> choicepatientupdate;

                            if (choicepatientupdate == 1)
                            {
                                cout << "Enter the patient's Id: ";
                                cin >> Id[t];
                            }
                            if (choicepatientupdate == 2)
                            {
                                cout << "Enter the patient's Name: ";
                                cin >> Name[t];
                            }
                            if (choicepatientupdate == 3)
                            {
                                cout << "Enter the patient's Gender: ";
                                cin >> Gender[t];
                            }
                            if (choicepatientupdate == 4)
                            {
                                cout << "Enter the patient's Age: ";
                                cin >> Age[t];
                            }
                            if (choicepatientupdate == 5)
                            {
                                cout << "Enter the patient's Disease: ";
                                cin >> Disease[t];
                            }
                            if (choicepatientupdate == 6)
                            {
                                cout << "Enter the patient's Phone: ";
                                cin >> Phone[t];
                            }
                            if (choicepatientupdate == 7)
                            {
                                cout << "Enter the patient's Id: ";
                                cin >> Id[t];
                                cout << "Enter the patient's Name: ";
                                cin >> Name[t];
                                cout << "Enter the patient's Gender: ";
                                cin >> Gender[t];
                                cout << "Enter the patient's Age: ";
                                cin >> Age[t];
                                cout << "Enter the patient's Disease: ";
                                cin >> Disease[t];
                                cout << "Enter the patient's Phone: ";
                                cin >> Phone[t];
                            }
                        }
                        else
                        {
                            cout << "Patient not found\n\n";
                        }

                        cout << "Do you want to update another patient's information (y/n): ";
                        cin >> continuationchoice3;

                    } while (continuationchoice3 == 'y' || continuationchoice3 == 'Y');
                }


            } while (choicepatientmanagement != 5);
        }
        if (choice == 3)   // <-- Use correct number for Appointment Module in your main menu
        {
            int appointmentChoice = 0;

            do
            {
                cout << "\t********************************************\n";
                cout << "\t*           APPOINTMENT  SYSTEM            *\n";
                cout << "\t********************************************\n";
                cout << "\t*       1-Book New Appointment             *\n";
                cout << "\t*       2-View All Appointments            *\n";
                cout << "\t*       3-Search Appointment               *\n";
                cout << "\t*       4-Update Appointment               *\n";
                cout << "\t*       5-Cancel Appointment               *\n";
                cout << "\t*       6-Exit to Main Menu                *\n";
                cout << "\t********************************************\n";
                cout << "                 ENTER YOUR CHOICE: ";
                cin >> appointmentChoice;


                /************** 1 ? BOOK NEW APPOINTMENT **************/
                if (appointmentChoice == 1)
                {
                    if (appointmentCount >= MAX_APPOINTMENTS)
                    {
                        cout << "Cannot book more appointments.\n";
                    }
                    else
                    {
                        cout << "Enter Appointment ID: ";
                        cin >> appointmentId[appointmentCount];

                        cout << "Enter Patient ID: ";
                        cin >> appointmentPatientId[appointmentCount];

                        cout << "Enter Doctor ID: ";
                        cin >> appointmentDoctorId[appointmentCount];

                        cout << "Enter Appointment Date: ";
                        cin >> appointmentDate[appointmentCount];

                        cout << "Enter Appointment Time: ";
                        cin >> appointmentTime[appointmentCount];

                        appointmentCount++;

                        cout << "Appointment booked successfully.\n";
                    }

                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }


                /************** 2 ? VIEW ALL APPOINTMENTS **************/
                else if (appointmentChoice == 2)
                {
                    cout << "========== ALL APPOINTMENTS ==========\n";

                    if (appointmentCount == 0)
                    {
                        cout << "No appointment records available.\n";
                    }
                    else
                    {
                        for (int i = 0; i < appointmentCount; i++)
                        {
                            cout << "Appointment ID : " << appointmentId[i] << endl;
                            cout << "Patient ID     : " << appointmentPatientId[i] << endl;
                            cout << "Doctor ID      : " << appointmentDoctorId[i] << endl;
                            cout << "Date           : " << appointmentDate[i] << endl;
                            cout << "Time           : " << appointmentTime[i] << endl;
                            cout << "--------------------------------------\n";
                        }
                    }

                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }


                /************** 3 ? SEARCH APPOINTMENT **************/
                else if (appointmentChoice == 3)
                {
                    int searchId;
                    bool found = false;

                    cout << "Enter Appointment ID: ";
                    cin >> searchId;

                    for (int i = 0; i < appointmentCount; i++)
                    {
                        if (appointmentId[i] == searchId)
                        {
                            cout << "========== APPOINTMENT DETAILS ==========\n";
                            cout << "Appointment ID : " << appointmentId[i] << endl;
                            cout << "Patient ID     : " << appointmentPatientId[i] << endl;
                            cout << "Doctor ID      : " << appointmentDoctorId[i] << endl;
                            cout << "Date           : " << appointmentDate[i] << endl;
                            cout << "Time           : " << appointmentTime[i] << endl;
                            cout << "=========================================\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << "Appointment record not found.\n";
                    }

                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }


                /************** 4 ? UPDATE APPOINTMENT **************/
                else if (appointmentChoice == 4)
                {
                    int updateId;
                    bool found = false;

                    cout << "Enter Appointment ID to update: ";
                    cin >> updateId;

                    for (int i = 0; i < appointmentCount; i++)
                    {
                        if (appointmentId[i] == updateId)
                        {
                            cout << "Enter New Patient ID: ";
                            cin >> appointmentPatientId[i];

                            cout << "Enter New Doctor ID: ";
                            cin >> appointmentDoctorId[i];

                            cout << "Enter New Date: ";
                            cin >> appointmentDate[i];

                            cout << "Enter New Time: ";
                            cin >> appointmentTime[i];

                            cout << "Appointment updated successfully.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << "Appointment not found.\n";
                    }

                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }


                /************** 5 ? CANCEL APPOINTMENT **************/
                else if (appointmentChoice == 5)
                {
                    int deleteId;
                    bool found = false;

                    cout << "Enter Appointment ID to cancel: ";
                    cin >> deleteId;

                    for (int i = 0; i < appointmentCount; i++)
                    {
                        if (appointmentId[i] == deleteId)
                        {
                            for (int j = i; j < appointmentCount - 1; j++)
                            {
                                appointmentId[j] = appointmentId[j + 1];
                                appointmentPatientId[j] = appointmentPatientId[j + 1];
                                appointmentDoctorId[j] = appointmentDoctorId[j + 1];
                                appointmentDate[j] = appointmentDate[j + 1];
                                appointmentTime[j] = appointmentTime[j + 1];
                            }

                            appointmentCount--;
                            cout << "Appointment cancelled successfully.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << "Appointment not found.\n";
                    }

                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }

            } while (appointmentChoice != 6);
        }
        else if (choice == 2)
        {
            int docChoice;

            do {
                cout << "\n=============================== Doctor Management ===============================\n";
                cout << "1. Add New Doctor\n";
                cout << "2. View All Doctors\n";
                cout << "3. Search Doctor\n";
                cout << "4. Update Doctor Record\n";
                cout << "5. Remove Doctor\n";
                cout << "6. Exit to Main Menu\n";
                cout << "===============================\n";
                cout << "Enter your choice: ";
                cin >> docChoice;;

                // Add Doctor
                if (docChoice == 1)
                {
                    if (doctorCount >= 100)
                    {
                        cout << "Doctor storage full.\n";
                    }
                    else
                    {
                        cout << "Enter Doctor ID: ";
                        cin >> docId[doctorCount];
                        cin.ignore();

                        cout << "Enter Doctor Name: ";
                        getline(cin, docName[doctorCount]);

                        cout << "Enter Specialization: ";
                        getline(cin, docSpec[doctorCount]);

                        cout << "Enter Gender: ";
                        getline(cin, docGender[doctorCount]);

                        cout << "Enter Age: ";
                        cin >> docAge[doctorCount];
                        cin.ignore();

                        cout << "Enter Phone: ";
                        getline(cin, docPhone[doctorCount]);

                        doctorCount++;

                        cout << "Doctor added successfully.\n";
                    }
                }

                // View All Doctors
                else if (docChoice == 2)
                {
                    if (doctorCount == 0)
                        cout << "No doctor records available.\n";
                    else
                    {
                        for (int i = 0; i < doctorCount; i++)
                        {
                            cout << "\tDoctor ID: " << docId[i] << endl;
                            cout << "\tName: " << docName[i] << endl;
                            cout << "\tSpecialization: " << docSpec[i] << endl;
                            cout << "\tGender: " << docGender[i] << endl;
                            cout << "\tAge: " << docAge[i] << endl;
                            cout << "\tPhone: " << docPhone[i] << endl;
                            cout << "\t---------------------------------\n";
                        }
                    }
                }

                // Search Doctor
                else if (docChoice == 3)
                {
                    int did;
                    bool found = false;

                    cout << "Enter Doctor ID: ";
                    cin >> did;

                    for (int i = 0; i < doctorCount; i++)
                    {
                        if (docId[i] == did)
                        {
                            cout << "Doctor ID: " << docId[i] << endl;
                            cout << "Name: " << docName[i] << endl;
                            cout << "Specialization: " << docSpec[i] << endl;
                            cout << "Gender: " << docGender[i] << endl;
                            cout << "Age: " << docAge[i] << endl;
                            cout << "Phone: " << docPhone[i] << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        cout << "Doctor not found.\n";
                }

                // Update Doctor
                else if (docChoice == 4)
                {
                    int did;
                    bool found = false;

                    cout << "Enter Doctor ID to update: ";
                    cin >> did;

                    for (int i = 0; i < doctorCount; i++)
                    {
                        if (docId[i] == did)
                        {
                            cout << "Enter New Name: ";
                            cin >> docName[i];
                            cout << "Enter New Specialization: ";
                            cin >> docSpec[i];
                            cout << "Enter New Gender: ";
                            cin >> docGender[i];
                            cout << "Enter New Age: ";
                            cin >> docAge[i];
                            cout << "Enter New Phone: ";
                            cin >> docPhone[i];

                            cout << "Record updated successfully.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        cout << "Doctor not found.\n";
                }

                // Remove Doctor
                else if (docChoice == 5)
                {
                    int did;
                    bool found = false;

                    cout << "Enter Doctor ID to remove: ";
                    cin >> did;

                    for (int i = 0; i < doctorCount; i++)
                    {
                        if (docId[i] == did)
                        {
                            for (int j = i; j < doctorCount - 1; j++)
                            {
                                docId[j] = docId[j + 1];
                                docName[j] = docName[j + 1];
                                docSpec[j] = docSpec[j + 1];
                                docGender[j] = docGender[j + 1];
                                docAge[j] = docAge[j + 1];
                                docPhone[j] = docPhone[j + 1];
                            }

                            doctorCount--;
                            cout << "Doctor removed successfully.\n";
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        cout << "Doctor not found.\n";
                }

            } while (docChoice != 6);
        }
        else if (choice == 5)
        {
            int choicereport = 0;
            do
            {
                cout << "****************\n";
                cout << "*              REPORTS MODULE               *\n";
                cout << "****************\n";
                cout << "* 1-View All Patients                       *\n";
                cout << "* 2-Search Patient by ID                   *\n";
                cout << "* 3-View Patients by Disease               *\n";
                cout << "* 4-View Patients by Age Group             *\n";
                cout << "* 5-View Gender-wise Patients              *\n";
                cout << "* 6-View Recent Admissions                 *\n";
                cout << "* 7-Exit                                   *\n";
                cout << "****************\n";
                cout << "ENTER YOUR CHOICE: ";
                cin >> choicereport;
                cin.ignore();

                // ---- All Patients ----
                if (choicereport == 1)
                {
                    if (patientcount == 0)
                        cout << "No records available.\n";

                    for (int i = 0; i < patientcount; i++)
                    {
                        cout << "ID: " << Id[i] << endl;
                        cout << "Name: " << Name[i] << endl;
                        cout << "Age: " << Age[i] << endl;
                        cout << "Gender: " << Gender[i] << endl;
                        cout << "Disease: " << Disease[i] << endl;
                        cout << "Phone: " << Phone[i] << endl;
                        cout << "-----------------------------\n";
                    }
                }

                // ---- Search by ID ----
                else if (choicereport == 2)
                {
                    int sid;
                    bool found = false;
                    cout << "Enter Patient ID: ";
                    cin >> sid;

                    for (int i = 0; i < patientcount; i++)
                    {
                        if (Id[i] == sid)
                        {
                            cout << "Name: " << Name[i] << endl;
                            cout << "Age: " << Age[i] << endl;
                            cout << "Gender: " << Gender[i] << endl;
                            cout << "Disease: " << Disease[i] << endl;
                            cout << "Phone: " << Phone[i] << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Patient not found.\n";
                }

                // ---- By Disease ----
                else if (choicereport == 3)
                {
                    string dis;
                    bool found = false;
                    cout << "Enter disease: ";
                    getline(cin, dis);

                    for (int i = 0; i < patientcount; i++)
                    {
                        if (Disease[i] == dis)
                        {
                            cout << "ID: " << Id[i] << endl;
                            cout << "Name: " << Name[i] << endl;
                            cout << "Age: " << Age[i] << endl;
                            cout << "Gender: " << Gender[i] << endl;
                            cout << "Disease: " << Disease[i] << endl;
                            cout << "Phone: " << Phone[i] << endl;
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "No patient found.\n";
                }

                // ---- By Age Group ----
                else if (choicereport == 4)
                {
                    int minAge, maxAge;
                    bool found = false;

                    cout << "Enter min age: ";
                    cin >> minAge;
                    cout << "Enter max age: ";
                    cin >> maxAge;

                    for (int i = 0; i < patientcount; i++)
                    {
                        if (Age[i] >= minAge && Age[i] <= maxAge)
                        {
                            cout << "ID: " << Id[i] << endl;
                            cout << "Name: " << Name[i] << endl;
                            cout << "Age: " << Age[i] << endl;
                            cout << "Gender: " << Gender[i] << endl;
                            cout << "Disease: " << Disease[i] << endl;
                            cout << "Phone: " << Phone[i] << endl;
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "No patient found.\n";
                }

                // ---- By Gender ----
                else if (choicereport == 5)
                {
                    string g;
                    bool found = false;
                    cout << "Enter gender (male/female): ";
                    getline(cin, g);

                    for (int i = 0; i < patientcount; i++)
                    {
                        if (Gender[i] == g)
                        {
                            cout << "ID: " << Id[i] << endl;
                            cout << "Name: " << Name[i] << endl;
                            cout << "Age: " << Age[i] << endl;
                            cout << "Gender: " << Gender[i] << endl;
                            cout << "Disease: " << Disease[i] << endl;
                            cout << "Phone: " << Phone[i] << endl;
                            found = true;
                        }
                    }
                    if (!found)
                        cout << "No patient found.\n";
                }

                // ---- Recent Admissions ----
                else if (choicereport == 6)
                {
                    if (patientcount == 0)
                        cout << "No admissions.\n";

                    for (int i = patientcount - 1; i >= 0 && i >= patientcount - 5; i--)
                    {
                        cout << "Name: " << Name[i] << endl;
                        cout << "Age: " << Age[i] << endl;
                        cout << "Gender: " << Gender[i] << endl;
                        cout << "Disease: " << Disease[i] << endl;
                        cout << "Phone: " << Phone[i] << endl;

                    }
                }

            } while (choicereport != 7);




        }
        // BILL MANAGEMENT by Muhammad Husnain
        else if (choice == 4)
        {
            int billChoice = 0;

            do
            {
                cout << "\n========== BILL MANAGEMENT ==========\n";
                cout << "1. Add Bill\n";
                cout << "2. View All Bills\n";
                cout << "3. Search Bill\n";
                cout << "4. Delete Bill\n";
                cout << "5. Exit\n";
                cout << "Enter choice: ";
                cin >> billChoice;

                // ---- ADD BILL ----
                if (billChoice == 1)
                {
                    int pid;
                    bool found = false;

                    cout << "Enter Bill ID: ";
                    cin >> billId[billCount];

                    cout << "Enter Patient ID: ";
                    cin >> pid;

                    for (int i = 0; i < patientcount; i++)
                    {
                        if (Id[i] == pid)
                        {
                            billPatientId[billCount] = pid;
                            billPatientName[billCount] = Name[i];
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        cout << "Patient not found. Bill not added.\n";
                    }
                    else
                    {
                        cout << "Enter Total Amount: ";
                        cin >> billTotal[billCount];
                        billCount++;
                        cout << "Bill added successfully.\n";
                    }
                }

                // ---- VIEW BILLS ----
                else if (billChoice == 2)
                {
                    if (billCount == 0)
                        cout << "No bills available.\n";
                    else
                    {
                        for (int i = 0; i < billCount; i++)
                        {
                            cout << "Bill ID: " << billId[i] << endl;
                            cout << "Patient Name: " << billPatientName[i] << endl;
                            cout << "Total Amount: " << billTotal[i] << endl;
                            cout << "-------------------------" << endl;
                        }
                    }
                }

                // ---- SEARCH BILL ----
                else if (billChoice == 3)
                {
                    int sid;
                    bool found = false;

                    cout << "Enter Bill ID: ";
                    cin >> sid;

                    for (int i = 0; i < billCount; i++)
                    {
                        if (billId[i] == sid)
                        {
                            cout << "Bill ID: " << billId[i] << endl;
                            cout << "Patient Name: " << billPatientName[i] << endl;
                            cout << "Total Amount: " << billTotal[i] << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        cout << "Bill not found.\n";
                }

                // ---- DELETE BILL ----
                else if (billChoice == 4)
                {
                    int did;
                    bool found = false;

                    cout << "Enter Bill ID to delete: ";
                    cin >> did;

                    for (int i = 0; i < billCount; i++)
                    {
                        if (billId[i] == did)
                        {
                            for (int j = i; j < billCount - 1; j++)
                            {
                                billId[j] = billId[j + 1];
                                billPatientId[j] = billPatientId[j + 1];
                                billPatientName[j] = billPatientName[j + 1];
                                billTotal[j] = billTotal[j + 1];
                            }
                            billCount--;
                            found = true;
                            cout << "Bill deleted successfully.\n";
                            break;
                        }
                    }
                    if (!found)
                        cout << "Bill not found.\n";
                }

            } while (billChoice != 5);
        }
    } while (choice != 6);

    return 0;
}
