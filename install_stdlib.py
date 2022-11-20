import os
import sysconfig
import shutil

def get_include_path() -> str:
    # TODO: venv support?
    if os.name == "posix":
        return sysconfig.get_path("include", "posix_user")
    elif os.name == "nt":
        return sysconfig.get_path("include", "nt")
    raise ValueError(f"Cannot determine include path on OS `{os.name}`, consider manual installation.")

if __name__ == "__main__":
    src = os.path.join(os.getcwd(), "include", "mlogevo")
    target = os.path.join(get_include_path(), "mlogevo")
    print("Installing MlogEvo standard library")
    print(f"source: {src}")
    print(f"destination: {target}")
    shutil.copytree(src=src, dst=target,
                    copy_function=shutil.copy
                    )
    print("Installation complete!")
