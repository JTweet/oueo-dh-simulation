/*
 * Input / Arguments:
 * Neither input nor arguments are required and / or supported.
 * Output:
 * Human-readable output is intentionally written to cerr (stderr) to allow for simple redirection of
 * CSV lines into a file through cout (stdout).
*/

#include <dh/dh.hpp>
#include <iostream>
#include <cstring>
#include <chrono>

int main(void) {
    unsigned int generator = 5;
    // Incrementing counter for test number
    unsigned int i = 0;
    // Track success of key-exchange
    bool exchangeSuccess;

    // Array contains safe primes in sizes 2048, 4096 and 8192 bit. Stored in array for easier following of DRY concepts.
    const char* testPrimes[] {
        "947ecd28cba68531cfa55c38285ea4e7429a452f07bdb27c79efecee2feae970aa6635c7f127e0199d6ff16e88c65a1838780996045b00fd13f9cb872f1a1fa596a65726644fdf6c7dedf00a304751b05070e4187519098117490dbe0a2b22f7daa8e9c0433626ef97cea652b74b68ecd9a072b6ff3cfcf1a0b3600178288a1e9901b33b04fad48ec36fbd2f7a6a52a67ab80ff3eebfe790b51f2bb2a0bc1a3d5953e4f92c41079e655b34f91722113cf2fc50bad7f689b28930c1ffc6a9a4f03078d518379cea292b2c4129fedf249ff965c76b6d1e56343bb453e3a937e01a56142d5fde94ab56a659905c9e62f363d91264298eebc5a92ae9d83526c6afbb",
        "e0192a47a141f7fea39b4ef7355635e24caafaa3d28cf23b4f2673249ae053912e1e278eba3ab58883656ebf2f51da5622424d8b801ab524f9c3b89e1bca74517536792833094147ac0e3ef555fb8c8b4e2fe618cefae3812946f01bd36cc28db7f9cfe09622e0072c9be3d011d385cc000ac2d133fed85254372e0c690da3506fa088d0449ce63223168404cd9a2c23bfb3e620eabb763654960e11ac457f24eeb6eabeffa02e21010d9db104f5d8ca8b8ba9c00a6664137a65e3b9bd345749f884784a62ee7b2d59150c11f31464108bf03f3ee6eafb7a54ffd7150b124094fdf8042e5f9209ae489a439dedcc06d8a0b2f207cd27bc7f5f2f03da844238d83d85ca8b721bc61dc489269bb0b57f4159229e409760d32ebe7d473411b88e61394329add5c70f3842048c1410293486a7ad069ebe73746e33e7d3dd1df7ec2822ef3cece5f0dfd75864730dd672653856311d253f5599e3fa70ad8c35c3aeeb48711039faad716757ce1bbebcfaf40d499256a1f5592f3f8cfbe7a20012b42af59fed6b9073fb5d1584ec6d5643faf81ddeb252153507c4bca76796f644d586e6bacc6592352815568e4f57b3ccaecf0f592583a2b6263ac589edf29dd4d004863604a80fa812af4bfc5f8d1a58243334ad4d43fc76348add8dcd3b5fc3202f0ca943cd218ce8a72cf26b155ccb66a435d56b88ea3da7f3ea49becf749fd093",
        "dfc278dab6a8ff24d8df98807d9d4b6ebc8e253a3795862833af57f66653263af8ee380313b1a93d64edfaf2a2e5e7c01547cb8f2c284c91358cdc32ce01515945687715de34558d5e8908fd3976652b7ce12ae3d59934ab8013f1a652fbf32e63864e168181947d08746b0bba2d70afaabc17ee0c68f1ad67e9779bd16e3d57c04133d2766c446453360f5f45304e667f84f2e5546b77b00f0d8116cc64afd3dc4bc3535efd93d40f30fb21be2d5434f7c898d7d035b633949d5ba505abeb8b3054b64fae8e883da227abce8df81ab10f8e964a1fccc9cce56964db890c50c752933d7b7e05a975fc63fa974bb7bd0de0d47f5c3bb6f7b7232ffe6ea17605a749c22299949b82724dedb98471f6226678e4420dcd77e8f067606a391b2c6d08889c2c9db9e54246c2a31d28add32cbf0456b6d27ebaf966fa7a4d7ba982a3777a53874710bc69632123688758373f3b1776248b95c3b969d22b4d3deaf8e3386f58810de2d14a339782a5bf8752b06bb6b3e29450aa68094b513cb24fffbe39577ec11c47754715ae137d502653ce9faaef3805bb7313416225a3645dd8e9cfb148262e8a924c729e5945581e0b1e3eca8fd8ae192ac44689985a1c3500c34e697cd4dc2f6e7929f3604de55bdb08b21fa2a6e4b62f48fea58d764a6adde24c7c18c698f031c1e3e793083747f32541be33f85de28072c3184cb973892a949ec64e80c4e07b26d0481913c5914e13faeaa33b2ad01568490ed04a011c1dadbc41db1120b8f2df72cf7945701fdfcb57c519f084903b09a0aabb5cf3c92d0884c922387f0edf656da127d7febacb278a355a93b287ea07e7f5d82f07db02d7c005c4492e8430b934cedfee20eedb4f9618becf3cb3c26392274d7e8e9d3b80ea55eda6ca53d328a4bfbb7a956aa71e042e89e2360f17549c10a28864d852fca6675f5fcd9331b8baf02497011044937a1104c5ca54ac5d3bf742ba6bb439d6c3bf4d892e05b758dbd46aa769c37c945e1efa07bc746f9fea436d6f102499be56ee0b0e806b2c8fbe8cc351bc8f63c213a63ba057b0d2819bf8b9492dd693a41d3bcfce0b11599cfb30b802435946a673ced180e6047a2c863c7870dfaa96de8115df535c816cbf6b0610eaf30bc4995974cf3f64a998472511e8a504a66d6a02f1e66cbca7f308b0470e1e1b2f83f318a2e4f5956cbf1d54d6472d03617972befb96d5ce803bc3872b14b1b3fb4a7d5128f39a810821a626be9edbdba3ca2a3e4e76b0fc43a0cf49a97a910dc2d36b3f7d448b89367cfffe8091392838c0cc70becf93b926395ab2ba3fd4693afdebd4a0efaa81f9a807cf2694962ebff96f7029dde4b2f641b56b01dd4f2c966975bc3dec192c4067f4a195e67e41bea36b61da5b45120a4861775318ca9ba9264f2aa5852834f699c97ffe1fc7114d31b587"
    };

    // Allocate variables in the main program, for display and comparison purposes.
    char *publicKeyAlice;
    char *publicKeyBob;
    char *sharedSecretAlice;
    char *sharedSecretBob;

    // Iterate over testPrimes, performing the same test setup over the different bitlengths.
    for (const char *v : testPrimes) {
        std::cerr << "Starting test " << i << std::endl;

        // Initialize exchangeSuccess
        exchangeSuccess = false;

        // Algorithm timing starts here
        const auto startTimer = std::chrono::high_resolution_clock::now();
        DiffieHellman dhAlice(generator, v);
        DiffieHellman dhBob(generator, v);

        // Retrieve public keys and send them to the other DiffieHellman instance, simulating an insecure channel
        publicKeyAlice = (char *) malloc(dhAlice.getPrimeBitLength() + 2);
        publicKeyBob = (char *) malloc(dhBob.getPrimeBitLength() + 2);
        dhAlice.getPublicKey(publicKeyAlice);
        dhBob.getPublicKey(publicKeyBob);
        dhAlice.importPartnerPublicKey(publicKeyBob);
        dhBob.importPartnerPublicKey(publicKeyAlice);

        // Algorithm timing ends here
        const auto endTimer = std::chrono::high_resolution_clock::now();

        // Retrieve the calculated shared secret and check for match, to verify correct function of Diffie-Hellman exchange
        sharedSecretAlice = (char *) malloc(dhAlice.getPrimeBitLength() + 2);
        sharedSecretBob = (char *) malloc(dhBob.getPrimeBitLength() + 2);
        dhAlice.getSharedSecret(sharedSecretAlice);
        dhBob.getSharedSecret(sharedSecretBob);
        // Compare the generated shared secrets, they are pointers the strcmp function is needed.
        if(strcmp(sharedSecretAlice, sharedSecretBob) == 0) {
            std::cerr << "Test " << i << ": The shared secrets do match." << std::endl;
            exchangeSuccess = true;
        } else {
            std::cerr << "Test " << i << ": The shared secrets do NOT match." << std::endl;
            exchangeSuccess = false;
        }

        // Release allocated memory
        free(publicKeyAlice);
        free(publicKeyBob);
        free(sharedSecretAlice);
        free(sharedSecretBob);

        // Calculate algorithm duration and print summary
        const std::chrono::duration<double> diffTimer = endTimer - startTimer;
        std::cerr << "Test " << i << ": DH exchange took " << diffTimer.count() << "s at " << dhAlice.getPrimeBitLength() << " bits. Start: " << startTimer.time_since_epoch().count() << "; End: " << endTimer.time_since_epoch().count() << std::endl;
        std::cerr << "Finished test " << i << "" << std::endl;
        // CSV fields: bitlength,duration_s,exchange_success
        std::cout << dhAlice.getPrimeBitLength() << "," << diffTimer.count() << "," << exchangeSuccess << std::endl;
        i++;
    }

    return 0;
}