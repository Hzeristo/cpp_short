#include "Common/common.h"
#include "event.h"
#include "item.h"
#include "gun.h"
#include "player.h"

class Game;
using GamePtr = std::shared_ptr<Game>;
class Game : public std::enable_shared_from_this<Game> {
public:
  Game(EventBus& bus);
  ~Game() {};

  void initItems();

  void subscribe();

  void onItemUsedEvent(std::shared_ptr<ItemUsedEvent> event);

private:
  std::vector<ItemPtr> items_me;
  std::vector<ItemPtr> items_ai;

  EventBus& bus;
};