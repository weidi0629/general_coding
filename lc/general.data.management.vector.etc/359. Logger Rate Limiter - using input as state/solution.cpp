/*
不用存目前的时间，但是把输入的时间做变化，成为下次的标准
*/
class Logger {
public:

    map<string, int> ok;

    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < ok[message])
            return false;
        ok[message] = timestamp + 10;
        return true;
    }
};
