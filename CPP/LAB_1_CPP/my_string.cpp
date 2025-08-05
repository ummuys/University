void strcpy(char* obj1, char* obj2) {
    int i = 0;
    for (; obj1[i]; i++) {
        obj2[i] = obj1[i];
    }
    obj2[i] = 0;
}