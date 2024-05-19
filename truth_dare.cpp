#include <iostream>
#include <string>
#include <random>

class Player {
public:
  Player(const std::string& name) : name_(name) {}

  std::string getName() const { return name_; }

private:
  std::string name_;
};

class Truth {
public:
  virtual void askTruth(const Player& player) const = 0;
};

class Dare {
public:
  virtual void askDare(const Player& player) const = 0;
};

class TruthList : public Truth {
public:
  void askTruth(const Player& player) const override {
    std::cout << player.getName() << ", answer honestly: What's your biggest fear?" << std::endl;
  }
};

class DareList : public Dare {
public:
  void askDare(const Player& player) const override {
    std::cout << player.getName() << ", dare you to sing a funny song!" << std::endl;
  }
};

class Game {
public:
  void play(const Player& player1, const Player& player2) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1); // 0 for truth, 1 for dare

    while (true) {
      int choice = dis(gen);
      if (choice == 0) {
        TruthList truth;
        truth.askTruth(player1);
      } else {
        DareList dare;
        dare.askDare(player2);
      }

      // Switch players for next round
      Player temp = player1;
      player1 = player2;
      player2 = temp;

      std::string continuePlaying;
      std::cout << "Play another round? (y/n): ";
      std::cin >> continuePlaying;
      if (continuePlaying != "y") {
        break;
      }
    }
  }
};

int main() {
  Player player1("Alice");
  Player player2("Bob");

  Game game;
  game.play(player1, player2);

  return 0;
}
