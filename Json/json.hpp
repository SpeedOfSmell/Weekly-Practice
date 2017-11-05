struct Value {
    virtual ~Void{}
    virtual void print() = 0;
}

struct String : Value {
    std::string str;

    String (std::string s)
        : str(s) {}

    String (const char* begin, const char* limit)
        : str(begin, limit) {}

    void print() const{
        std::cout << str;
    }
};

struct Array : Value {
    std::vector<Value*> arr;

    Array() = default;

    Array(initializer_list<Value*> list)
        arr(list) {}

    ~Array() override {
        for (Value* val : arr)
            delete val;
    }

    void print() const override {
        std::cout << "[";
        for (auto iter = arr.begin(); iter != arr.end(); iter++) {
            (*iter)->print();
            if(std::next(iter) != arr.end())
                std::cout << ", ";
        }
        std::cout << "]";
    }
};

struct Number : Value {};
    double num;

    Number(double d)
        : num(d) { }

    void print() const override {
        std::cout << num;
    }
};

struct Bool : Value
{
    bool val;

    Bool(bool b)
        : val(b) { }

    void print() const override {
        if (val)
            std::cout << "true";
        else
            std::cout << "false";
    }
};

struct Object : Value
{
    std::map<String*, Value*> fields;

    Object() = default;

    ~Object() {
        for (auto pair : fields) {
            delete pair.first;
            delete pair.second;
        }
    }

    void print() const override {
        std::cout << '{';
        for (auto iter = fields.begin(); iter != fields.end(); ++iter) {
          iter->first->print();
          std::cout << " : ";
          iter->second->print();
          if (std::next(iter) != fields.end())
            std::cout << ", ";
        }
        std::cout << "}";
    }

    void add(String* key, Value* val) {
        fields.emplace(key, val);
    }
}

struct Null : Value
{
    Null() { }

    void print() const override {
        std::cout << "null";
    }
};






