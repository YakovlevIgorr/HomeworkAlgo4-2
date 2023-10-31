#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size, std::string text){
    std::cout << text;
    for(int i = 0; i < logical_size; i++){
        std::cout << arr[i] << " ";
    }

    for(int k = logical_size; k < actual_size; k++){
        std::cout << "_ ";
    }
}

int* create_arr(int* arr, int* actual_size, int* logical_size, int added_element){
    *actual_size *= 2;
    int* array = new int[*actual_size];

    for(int i = 0; i < *logical_size; i++){
        array[i] = arr[i];
    }
    array[*logical_size] = added_element;

    delete[] arr;
    return array;
}

int main() {

    int actual_size;
    int logical_size;
    int add_element;

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    int* arr = new int[actual_size]();


    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if(actual_size >= logical_size) {
        for (int i = 0; i < logical_size; i++) {
            std::cout << "Введите arr[" << i << "]: ";
            std::cin >> arr[i];
            //if(arr[i] == 0) break;
        }
        print_dynamic_array(arr, logical_size, actual_size, "Динамический массив: ");// arr, 3 , 5

        while (add_element != 0) {
            std::cout << "\nВведите элемент для добавления: ";
            std::cin >> add_element;
            if(add_element == 0) {
                print_dynamic_array(arr, logical_size, actual_size, "Спасибо! Ваш массив: ");
                break;
            }

            if(logical_size >= actual_size) {
                arr = create_arr(arr, &actual_size, &logical_size, add_element);
            }else arr[logical_size] = add_element;
            logical_size ++;
            print_dynamic_array(arr, logical_size, actual_size, "Динамический массив: ");
        }






    }else std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";



    delete[] arr;
    return 0;
}