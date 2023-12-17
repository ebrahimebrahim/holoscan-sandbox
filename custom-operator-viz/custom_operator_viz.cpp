#include <holoscan/holoscan.hpp>
#include "custom_op.hpp"
#include <holoscan/operators/holoviz/holoviz.hpp>

class CustomOperatorApp : public holoscan::Application {
 public:
  void compose() override {
    using namespace holoscan;

    // Define the replayer and holoviz operators and configure using yaml configuration
    auto replayer = make_operator<ops::CustomOp>("replayer", from_config("custom_op"));
    auto visualizer = make_operator<ops::HolovizOp>("holoviz", from_config("holoviz"));

    // Define the workflow: replayer -> holoviz
    add_flow(replayer, visualizer, {{"output", "receivers"}});
  }
};

int main(int argc, char** argv) {
  // Get the yaml configuration file
  auto config_path = std::filesystem::canonical(argv[0]).parent_path();
  config_path /= std::filesystem::path("custom_op_config.yaml");
  if ( argc >= 2 ) {
    config_path = argv[1];
  }

  auto app = holoscan::make_application<CustomOperatorApp>();
  app->config(config_path);
  app->run();

  return 0;
}