class FramePlayer {
private:
    uint16_t fps;
    uint32_t totalFrames;
    uint32_t startTime;
    uint32_t currentFrame;
    bool firstFrame;

public:
    FramePlayer(uint16_t targetFPS, uint32_t frameCount) {
        fps = targetFPS;
        totalFrames = frameCount;
        startTime = 0;
        currentFrame = 0;
        firstFrame = true;
    }

    void begin() {
      startTime = millis();
    }
    
    uint32_t getCurrentFrame() {
      uint32_t elapsedTime = millis() - startTime;
      return (elapsedTime * fps) % 1000;
    }

    uint32_t getFrame() {
      return currentFrame;
    }

    bool update() {
      if (firstFrame == true) {
        firstFrame = false;
        currentFrame = getCurrentFrame();
        return true;
      }
      uint32_t newFrame = getCurrentFrame();

      if (newFrame != currentFrame) {
        currentFrame = newFrame;
        return true;
    }

      return false;
    }

    void reset() {
      startTime = millis();
      currentFrame = 0;
      firstFrame = true;
    } 

    uint32_t getFrame() {
      return currentFrame;
    }

    void setFPS(uint16_t newFPS) {
      fps = newFPS;
    }
};

FramePlayer player(20, 120);

void setup() {
  Serial.begin(115200);
  player.begin();
}

void loop() {
  uint32_t frame = player.update();
  Serial.println(frame);

  if (player.update()) {
    uint32_t frame = player.getFrame();
  }
}
