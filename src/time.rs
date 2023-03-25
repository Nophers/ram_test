use std::time::Instant;

fn time_taken() {
    let start_time = Instant::now();

    // function here kek();

    let end_time = Instant::now();
    let duration = end_time.duration_since(start_time);
    println!("Time taken: {} ms", duration.as_millis());
}
