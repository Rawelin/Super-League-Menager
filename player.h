#ifndef PLAYER_H
#define PLAYER_H

#include <QtWidgets>
#include "gamewindow.h"
#include "showsquads.h"
#include "addplayer.h"
#include "serialization.h"
#include "editplayer.h"
#include "playersupportfunction.h"

class PlayerSupportFunction;

class Player
{
private:
    int id;
    QString fname;
    QString lname;
    QString nationality;
    QString position;
    int age;
    double gkeeper;
    double defence;
    double midfield;
    double attack;
    double tackle;
    double technik;
    double shot;
    double pass;
    double header;
    double speed;
    double endurance;
    int goals;
    double stamina;

    int overall;
    int shot_temp;
    int number;
    int first_team;
    QPixmap foto;
    QString foto_path;

    double rateEnergy();

    PlayerSupportFunction *player_support_function;

public:
    Player(){}
    Player(const QString& fn,const QString& ln, QString& nat, QString& pos, int a, double gk,
           double def, double mid, double att, double tack, double tech, double sh, double pa,
           double he, double spd, double end, double go, int over)
    : fname(fn), lname(ln),nationality(nat), position(pos), age(a), gkeeper(gk), defence(def),
      midfield(mid), attack(att), tackle(tack), technik(tech), shot(sh), pass(pa), header(he),
      speed(spd), endurance(end),goals(go), stamina(100), overall(over), shot_temp(0){}
    ~Player(){}

    int getId()const{return id;}
    QString getFname()const{return fname;}
    QString getLname()const{return lname;}
    QString getNationality()const{return nationality;}
    QString getPosition()const{return position;}
    double getGkeeper()const{return gkeeper;}
    double getDefence()const{return defence;}
    double getMidfield()const{return midfield;}
    double getAttack()const{return attack;}
    double getTackle()const{return tackle;}
    double getTechnik()const{return technik;}
    double getShot()const{return shot;}
    double getPass()const{return pass;}
    double getHeader()const{return header;}
    double getSpeed()const{return speed;}
    double getEndurance()const{return endurance;}
    int getGoals()const{return goals;}
    double calcEnergy();
    int getOverall(int, int);
    int getEnergyOverall(int, int);
    int getRealOveral();
    int getNumber()const{return number;}
    void staminaDecreaser(QVector<Player> &, int);
    void playerRecovery(QVector<Player> &);

    int getAge()const{return age;}
    int getShotTemp()const{return shot_temp;}
    int getStamina()const{return stamina;}
    int getFirstTeam()const{return first_team;}

    QPixmap getFoto() const;
    QString getFotoPath() const;

    void setShotTemp(int sh){shot_temp = sh;}
    void setGoal(){goals++;}

    void setId(int i){id = i;}
    void setFname(QString fn) {fname = fn;}
    void setLname(QString ln) {lname = ln;}
    void setNationality(QString nat){nationality = nat;}
    void setPosition(QString pos){position = pos;}
    void setAge(int a){age = a;}
    void setGkeeper(double g) {gkeeper = g;}
    void setDefence(double d) {defence = d;}
    void setMidfield(double m) {midfield = m;}
    void setAttack(double a) {attack = a;}
    void setTackle(double tck) {tackle = tck;}
    void setTechnik(double tech){technik = tech;}
    void setShot(double sh){shot = sh;}
    void setPass(double pa){pass = pa;}
    void setHeader(double he){header = he;}
    void setSpeed(double spd){speed = spd;}
    void setEndurance(double end){endurance = end;}
    void setGoals2(int g){goals = g;}
    void setPower(double p){stamina = p;}
    void setStamina(double sta){stamina = sta;}
    void setFirstTeam(int first){first_team = first;}
    void setFoto(const QPixmap &value);
    void setPlayerSupportFunction();
    void setFotoPath(const QString &value);

    static void swapPlayer(Player &, Player &);
};


#endif // PLAYER_H
