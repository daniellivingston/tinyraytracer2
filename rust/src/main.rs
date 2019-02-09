extern crate raster;
use raster::Image;
use raster::Color;

fn render() {
    const WIDTH: i32 = 1024;
    const HEIGHT: i32 = 768;

    let mut image = Image::blank(WIDTH,HEIGHT);

    image.set_pixel(10, 10, Color::rgba(255, 0, 0, 255)).unwrap();

    raster::save(&image, "test_me.png");

}

fn main() {
    render();
    println!("Hello, world!");
}