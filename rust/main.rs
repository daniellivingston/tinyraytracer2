fn render() {
    let width = 1024;
    let height = 768;
}

fn testme() {
    let mut vec = Vec::new();
    vec.push(1);
    vec.push(2);

    assert_eq!(vec.len(), 2);
    assert_eq!(vec[0], 1);

    assert_eq!(vec.pop(), Some(2));
    assert_eq!(vec.len(), 1);

    vec[0] = 7;
    assert_eq!(vec[0], 7);

    vec.extend([1, 2, 3].iter().cloned());

    for x in &vec {
        println!("{}", x);
    }
    assert_eq!(vec, [7, 1, 2, 3]);
}

fn main() {

    render();
    testme();

    println!("Hello, world!");
}




struct Vec3f<T> {
    _dim: T,
    //data: Vec::new(),
}

