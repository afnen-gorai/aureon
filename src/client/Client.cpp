#include "Client.h"
#include <QRegularExpression>

Client::Client(const QString &nom, const QString &telephone, 
               const QString &email, const QString &sexe)
    : m_nom(nom), m_telephone(telephone), m_email(email), m_sexe(sexe)
{
}

// Getters
QString Client::getNom() const { 
    return m_nom; 
}

QString Client::getTelephone() const { 
    return m_telephone; 
}

QString Client::getEmail() const { 
    return m_email; 
}

QString Client::getSexe() const { 
    return m_sexe; 
}

// Setters
void Client::setNom(const QString &nom) { 
    m_nom = nom; 
}

void Client::setTelephone(const QString &telephone) { 
    m_telephone = telephone; 
}

void Client::setEmail(const QString &email) { 
    m_email = email; 
}

void Client::setSexe(const QString &sexe) { 
    m_sexe = sexe; 
}

// Validation
bool Client::estValide() const {
    return !m_nom.isEmpty() && 
           !m_telephone.isEmpty() && 
           !m_email.isEmpty() && 
           !m_sexe.isEmpty() &&
           validerEmail(m_email);
}

bool Client::validerEmail(const QString &email) {
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return regex.match(email).hasMatch();
}

QString Client::toString() const {
    return QString("Client: %1 | Tel: %2 | Email: %3 | Sexe: %4")
        .arg(m_nom)
        .arg(m_telephone)
        .arg(m_email)
        .arg(m_sexe);
}
