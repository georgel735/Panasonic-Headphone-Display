constexpr uint16_t TARGET_FPS = 20;
constexpr uint32_t FRAME_INTERVAL_MS = 1000UL / TARGET_FPS;

uint32_t lastFrameTime = 0;
uint32_t frameNumber = 0;
uint32_t fpsCounter = 0;
uint32_t lastCount = 0;
uint32_t playbackStartTime = 0;
uint32_t totalFrames = 120;

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint32_t currentTime = millis();
  if (currentTime - lastFrameTime >= FRAME_INTERVAL_MS) {
    lastFrameTime += FRAME_INTERVAL_MS;
    frameNumber++;
    fpsCounter++;
    Serial.println(frameNumber);
  }

  if (currentTime - lastCount >= 1000) {
    Serial.println(fpsCounter);
    fpsCounter = 0;
    lastCount = currentTime;
  }
}
