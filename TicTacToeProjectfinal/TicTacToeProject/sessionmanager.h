#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QString>

class SessionManager {
public:
    static SessionManager& instance() {
        static SessionManager instance;
        return instance;
    }

    void login(const QString &username) {
        currentUser = username;
    }

    void logout() {
        currentUser.clear();
    }

    QString getCurrentUser() const {
        return currentUser;
    }

private:
    QString currentUser;
    SessionManager() {}
    ~SessionManager() {}
};

#endif // SESSIONMANAGER_H
